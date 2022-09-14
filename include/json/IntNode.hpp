#pragma once

#include "json/Node.hpp"

namespace json {
    class IntNode : public Node {
    public: 
        IntNode(int i) : val(i) {}
        std::string to_json();
        int value() { return val; }
    private:
        int val;
    };
}