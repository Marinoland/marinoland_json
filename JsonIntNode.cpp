#include "JsonIntNode.hpp"

using namespace std;
namespace json {
    string JsonIntNode::to_json() {
        return ::to_string(val);
    }
}