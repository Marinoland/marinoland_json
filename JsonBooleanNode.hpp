#ifndef __JSONBOOLEANODE_HPP__
#define __JSONBOOLEANNODE_HPP__

#include "JsonNode.hpp"

namespace json {

    class JsonBooleanNode : public JsonNode {
    public: 
        JsonBooleanNode(int newFlag) : flag(newFlag) { }
        std::string to_string() {
            return flag?"true":"false";
        }
    private:
        int flag;
    };

}

#endif