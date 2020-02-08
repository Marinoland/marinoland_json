#ifndef __JSONARRAYNODE_HPP__
#define __JSONARRAYNODE_HPP__

#include "JsonNode.hpp"
#include <vector>

namespace json {
    class JsonArrayNode : public JsonNode {
    public: 
        void add(nodeptr node);
        std::string to_json();
        std::vector<nodeptr>::iterator begin() {
            return data.begin();
        }
        std::vector<nodeptr>::iterator end() {
            return data.end();
        }
        virtual void asArray(arrayCast fn){fn(*this);};
    private:
        std::vector<nodeptr> data;
    };
}

#endif