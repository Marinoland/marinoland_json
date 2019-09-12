#include "JsonNullNode.hpp"

using namespace std;

namespace json {

    string JsonNullNode::to_string() {
        return "null";
    }
}