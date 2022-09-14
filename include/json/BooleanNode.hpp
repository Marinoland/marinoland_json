#pragma once

#include "json/Node.hpp"

namespace json {

    class BooleanNode : public Node {
    public: 
        BooleanNode(int newFlag) : flag(newFlag) { }
        std::string to_json() {
            return flag?"true":"false";
        }
        int value() { return flag; }
    private:
        int flag;
    };

}