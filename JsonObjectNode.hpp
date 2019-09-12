#ifndef __JSONOBJECTNODE_HPP__
#define __JSONOBJECTNODE_HPP__

#include "JsonNode.hpp"
#include <map>

namespace json {
    class JsonObjectNode : public JsonNode {
    public: 
        void set(std::string key, nodeptr);
        std::string to_string();
    private:
        std::map<string, nodeptr> values;
    };
}

#endif