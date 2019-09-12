#ifndef __JSONINTNODE_HPP__
#define __JSONINTNODE_HPP__

#include "JsonNode.hpp"

namespace json {
    class JsonIntNode : public JsonNode {
    public: 
        JsonIntNode(int i) : val(i) {}
        std::string to_string();
    private:
        int val;
    };
}

#endif