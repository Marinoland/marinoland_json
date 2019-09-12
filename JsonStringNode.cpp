#include "JsonStringNode.hpp"

using namespace std;

namespace json {

    string JsonStringNode::to_string()
    {
        string ret = "\"";
        for(char c : val)
        {
            if(c=='\"') ret += "\\\"";
            else if(c=='\\') ret += "\\\\";
            else if(c=='/') ret += "\\/";
            else if(c=='\f') ret += "\\f";
            else if(c=='\n') ret += "\\n";
            else if(c=='\r') ret += "\\r";
            else if(c=='\t') ret += "\\t";
            else ret += c;
        }
        ret += '"';
        return ret;
    }
}