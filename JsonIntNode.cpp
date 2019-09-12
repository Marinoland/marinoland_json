#include "JsonIntNode.hpp"

using namespace std;
namespace json {
    string JsonIntNode::to_string() {
        return ::to_string(val);
    }
}