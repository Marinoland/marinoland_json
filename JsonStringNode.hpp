#ifndef __JSONSTRINGNODE_HPP__
#define __JSONSTRINGNODE_HPP__

#include "JsonNode.hpp"

namespace json {
    class JsonStringNode : public JsonNode {
    public: 
        JsonStringNode(std::string str) : val(str) {}
        std::string getString() {return val;}
        std::string to_json();
        std::string to_string();
    private:
        std::string val;
    };
}

#endif