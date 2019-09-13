#include "JsonObjectNode.hpp"
#include <sstream>

using namespace std;
namespace json {
    void JsonObjectNode::set(string key, nodeptr node) {
        values[key] = node;
    }

    string JsonObjectNode::to_string() {
        stringstream ss;
        ss << '{';
        for(map<string, nodeptr>::iterator i = values.begin();
        i != values.end(); i++ ) {
            if(i != values.begin()) ss << ',';
            ss << '"' <<  i->first << "\":" << i->second->to_string();
        }
        ss << '}';
        return ss.str();
    }
}