#include "JsonNullNode.hpp"

using namespace std;

namespace json {

    string JsonNullNode::to_json() {
        return "null";
    }
}