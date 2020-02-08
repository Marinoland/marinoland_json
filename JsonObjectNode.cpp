#include "JsonObjectNode.hpp"
#include <sstream>

using namespace std;
namespace json {
    void JsonObjectNode::set(string key, nodeptr node) {
        values[key] = node;
    }

    nodeptr JsonObjectNode::get(string key) {
        return values[key];
    }

    string JsonObjectNode::to_json() {
        stringstream ss;
        ss << '{';
        for(map<string, nodeptr>::iterator i = values.begin();
        i != values.end(); i++ ) {
            if(i != values.begin()) ss << ',';
            ss << '"' <<  i->first << "\":" << i->second->to_json();
        }
        ss << '}';
        return ss.str();
    }
}