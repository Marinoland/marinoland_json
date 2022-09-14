#pragma once

#include "json/Node.hpp"

namespace json {
    using namespace std;
    class StringNode : public Node {
    public: 
        StringNode(string str) : val(str) {}
        string value() {return val;}
        string to_json();
        string to_string();
    private:
        string val;
    };
}