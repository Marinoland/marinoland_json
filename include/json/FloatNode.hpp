#pragma once

#include "json/Node.hpp"

namespace json {

    class FloatNode : public Node {
    public: 
        FloatNode(float newVal) : val(newVal){}
        std::string to_json();
        float value() { return val; }
    private:
        float val;
    };
}