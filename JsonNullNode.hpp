#ifndef __JSONNULLNODE_HPP__
#define __JSONNULLNODE_HPP__

#include "JsonNode.hpp"

namespace json {
    
    class JsonNullNode : public JsonNode {
    public: 
        std::string to_string();
    private:
    };
}

#endif