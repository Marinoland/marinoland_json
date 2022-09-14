#include "json/NullNode.hpp"

using namespace std;

namespace json {

    string NullNode::to_json() {
        return "null";
    }
}