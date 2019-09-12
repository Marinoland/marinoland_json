#include "JsonFloatNode.hpp"

#include <iostream>
using namespace std;

namespace json {
    string JsonFloatNode::to_string() {
        return ::to_string(val);
    }
}