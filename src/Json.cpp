#include "json/Json.hpp"
#include <iostream>
#include <fstream>

using namespace std;


namespace json
{
    char *skipwhite(char *c)
    {
        while(*c == ' ' || *c == '\t' || *c == '\n' || *c == '\r') c++;
        return c;
    }

    int match(char *c, char *match)
    {
        while(*match)
        {
            if(*c != *match) return 0;
            ++c;
            ++match;
        }
        return true;
    }

    typedef function<void(char*c, nodeptr)> success;
    typedef function<void(char*c, string msg)> failure;

    int stop_null(char *c, success s, failure f)
    {
        if(match(c, (char*)"null"))
        {
            s(c+4, make_shared<NullNode>());
            return true;
        }
        return false;
    }

    int stop_boolean(char *c, success s, failure f)
    {
        if(match(c, (char*)"true"))
        {
            s(c+4, make_shared<BooleanNode>(1));
            return true;
        }
        else if(match(c, (char*)"false"))
        {
            s(c+5, make_shared<BooleanNode>(0));
            return true;
        }
        return false;
    }

    int stop_num(char *c, success s, failure f)
    {
        string str1, str2;
        while(*c >= '0' && *c <= '9') {str1 += *c; ++c;}
        if(str1.length() == 0) return false;
        if(*c == '.') 
        {
            ++c;
            while(*c >= '0' && *c <= '9') {str2 += *c; c++;}
            if(str2.length() == 0) return false;
            s(c, make_shared<FloatNode>(::atof((str1 + '.' + str2).c_str())));
        } else {
            s(c, make_shared<IntNode>(::atoi(str1.c_str())));
        }
        return true;
    }

    int stop_string(char *c, success s, failure f)
    {
        if(*c != '"')
        {
            return false;
        }
        string str;
        ++c;
        while(*c != '"')
        {
            if(!*c)
            {
                f(c, "Unexpected end of file while reading string");
                return 1;
            }
            if(match(c, (char*)"\\\"")) {str+="\""; c+=2;}
            else if(match(c, (char*)"\\\\")) {str+="\\"; c+=2;} 
            else if(match(c, (char*)"\\/")) {str+="/"; c+=2;} 
            else if(match(c, (char*)"\\b")) {c+=2;} 
            else if(match(c, (char*)"\\f")) {str+="\f"; c+=2;} 
            else if(match(c, (char*)"\\n")) {str+="\n"; c+=2;} 
            else if(match(c, (char*)"\\r")) {str+="\r"; c+=2;} 
            else if(match(c, (char*)"\\t")) {str+="\t"; c+=2;} 
            //else if(match(c, (char*)"\\u")) {str+="\\u"; c+=6;} //todo handle /uXXXX correctly
            else {str += *c; c++;}
        }
        s(c+1, make_shared<StringNode>(str));
        return true;
    }

    int stop_any(char *c, success s, failure f);

    int stop_object(char *c, success s, failure f)
    {
        if(*c != '{') return false;
        c++;
        c=skipwhite(c);
        shared_ptr<ObjectNode> objectNode = make_shared<ObjectNode>();
        while(*c != '}')
        {
            if(!*c)
            {
                f(c, "Unexpected end of string while reading object");
                return 1;
            } 
            else 
            {
                string key;
                string errormsg;
                if(stop_string(c,
                [&](char *newC, nodeptr strptr) {
                    c = newC;
                    key = ((StringNode*)strptr.get())->value();

                },
                [&](char *newC, string msg) {
                    c = newC;
                    errormsg = msg;
                })) {
                    if(errormsg.length() > 0) {
                        f(c, errormsg);
                        return true;
                    }
                    c=skipwhite(c);
                    if(*c != ':') {
                        f(c, "Expected ':'");
                        return true;
                    }
                    c++;
                    c=skipwhite(c);
                    if(stop_any(c,
                        [&] (char *newC, nodeptr newNode)
                        {
                            c = newC;
                            objectNode->set(key, newNode);
                        },
                        [&] (char *newC, string msg)
                        {
                            errormsg = msg;
                            f(newC, msg);
                        }))
                    {
                        if(errormsg.length()) return true;

                        c=skipwhite(c);
                        if(*c == ',') 
                        {
                            c=skipwhite(c+1);
                        }
                        else if(*c != '}')
                        {
                            f(c, "Invalid character");
                            return true;
                        }
                    }
                    else
                    {
                        f(c, "Found invalid data element in the object");
                        return true;
                    }

                }
                else {
                    f(c, "Error reading object key");
                    return 1;
                }
            }
        }

        c++;
        s(c, objectNode);
        return true;
    }

    int stop_array(char *c, success s, failure f)
    {
        if(*c != '[') return false;
        c++;
        c=skipwhite(c);
        shared_ptr<ArrayNode> arrayNode = make_shared<ArrayNode>();
        while(*c != ']')
        {
            if(!*c)
            {
                f(c, "Unexpected end of string while reading array");
                return 1;
            }
            else
            {
                string errormsg;
                if(stop_any(c,
                    [&] (char *newC, nodeptr newNode)
                    {
                        c = newC;
                        arrayNode->add(newNode);
                    },
                    [&] (char *newC, string msg)
                    {
                        errormsg = msg;
                        f(newC, msg);
                    }))
                {
                    if(errormsg.length()) return true;

                    c=skipwhite(c);
                    if(*c == ',') 
                    {
                        c=skipwhite(c+1);
                    }
                    else if(*c != ']')
                    {
                        f(c, "Invalid character");
                        return true;
                    }
                }
                else
                {
                    f(c, "Found invalid data element in the array");
                    return true;
                }

            }
        }
        c++;
        s(c, arrayNode);
        return true;
    }

    int stop_any(char *c, success s, failure f)
    {
        c = skipwhite(c);
        nodeptr node;
        string failureMsg;

        success handleNode =
            [&](char *newC, nodeptr newNode)
            {
                c = newC;
                node = newNode;
            };

        failure handleFailure = 
            [&](char *newC, string msg)
            {
                c = newC;
                failureMsg = msg;
            };

        if( stop_string(c, handleNode, handleFailure) ||
            stop_array(c, handleNode, handleFailure) ||
            stop_object(c, handleNode, handleFailure) ||
            stop_num(c, handleNode, handleFailure) ||
            stop_null(c, handleNode, handleFailure) ||
            stop_boolean(c, handleNode, handleFailure))
        {
            if(failureMsg.length())
            {
                f(c, failureMsg);
            }
            else
            {
                s(c, node);
            }
            return true;
        }
        else
        {
            f(c, "unable to find any json element");
            return false;
        }
    }

    void parse(string src, function<void(nodeptr)> s, function<void(string)> f)
    {
        char *c_str = (char *)src.c_str();

        stop_any(c_str,
        [&](char *c, nodeptr node)
        {
            s(node);
        },
        [&](char *c, string msg)
        {
            f(msg + " : at position " + to_string(c-c_str));
        });
    }

    void fromFile(string filename, function<void(nodeptr)> s, function<void(string)> f) {
        fstream in;
        in.open(filename);
        string buffer;
        in.seekg(0, std::ios::end);
        buffer.reserve(in.tellg());
        in.seekg(0, std::ios::beg);
        buffer.assign(istreambuf_iterator<char>(in), istreambuf_iterator<char>());
        parse(buffer, s, f);
    }
}