#ifndef __JSONOBJECTNODE_HPP__
#define __JSONOBJECTNODE_HPP__

#include "JsonNode.hpp"
#include <string>
#include <map>

namespace json {
    class JsonObjectNode : public JsonNode {
    public: 
        void set(std::string key, nodeptr);
        std::string to_string();
    private:
        std::map<std::string, nodeptr> values;
    };
}

#endif