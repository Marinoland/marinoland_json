#ifndef __JSONSTRINGNODE_HPP__
#define __JSONSTRINGNODE_HPP__

#include "JsonNode.hpp"

namespace json {
    using namespace std;
    class JsonStringNode : public JsonNode {
    public: 
        JsonStringNode(string str) : val(str) {}
        string value() {return val;}
        string to_json();
        string to_string();
    private:
        string val;
    };
}

#endif