#pragma once

#include "json/Node.hpp"
#include <vector>

namespace json {
    class ArrayNode : public Node {
    public: 
        void add(nodeptr node);
        std::string to_json();
        std::vector<nodeptr>::iterator begin() {
            return data.begin();
        }
        std::vector<nodeptr>::iterator end() {
            return data.end();
        }
        //deprecated
        virtual void asArray(arrayCast fn){fn(*this);};
        virtual ArrayNode* asArray(){ return this; };
    private:
        std::vector<nodeptr> data;
    };
}