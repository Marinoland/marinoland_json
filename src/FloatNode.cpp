#include "json/FloatNode.hpp"

#include <iostream>
using namespace std;

namespace json {
    string FloatNode::to_json() {
        return ::to_string(val);
    }
}