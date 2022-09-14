#include "json/IntNode.hpp"

using namespace std;
namespace json {
    string IntNode::to_json() {
        return ::to_string(val);
    }
}