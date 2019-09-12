#ifndef __JSONARRAYNODE_HPP__
#define __JSONARRAYNODE_HPP__

#include "JsonNode.hpp"
#include <vector>

namespace json {
    class JsonArrayNode : public JsonNode {
    public: 
        void add(nodeptr node);
        std::string to_string();
    private:
        std::vector<nodeptr> data;
    };
}

#endif