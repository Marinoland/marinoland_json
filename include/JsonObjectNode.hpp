#ifndef __JSONOBJECTNODE_HPP__
#define __JSONOBJECTNODE_HPP__

#include "JsonNode.hpp"
#include <string>
#include <map>

namespace json {
    class JsonObjectNode : public JsonNode {
    public: 
        void set(std::string key, nodeptr);
        nodeptr get(std::string key);
        virtual void asObject(objectCast fn){fn(*this);};
        std::string to_json();
    private:
        std::map<std::string, nodeptr> values;
    };
}

#endif