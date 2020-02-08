#ifndef __JSONFLOATNODE_HPP__
#define __JSONFLOATNODE_HPP__

#include "JsonNode.hpp"

namespace json {

    class JsonFloatNode : public JsonNode {
    public: 
        JsonFloatNode(float newVal) : val(newVal){}
        std::string to_json();
    private:
        float val;
    };
}

#endif