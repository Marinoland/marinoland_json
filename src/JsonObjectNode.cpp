#include "JsonObjectNode.hpp"
#include "JsonStringNode.hpp"
#include "JsonIntNode.hpp"
#include "JsonBooleanNode.hpp"
#include "JsonFloatNode.hpp"
#include <sstream>

using namespace std;
namespace json {
    void JsonObjectNode::set(string key, nodeptr node) {
        values[key] = node;
    }

    nodeptr JsonObjectNode::get(string key) {
        return values[key];
    }

    string JsonObjectNode::getString(string key) {
        JsonStringNode* node = dynamic_cast<JsonStringNode*>(get(key).get());
        return (node)?node->value():"";
    }
    int JsonObjectNode::getInteger(string key) {
        JsonIntNode* node = dynamic_cast<JsonIntNode*>(get(key).get());
        return (node)?node->value():0;
    }
    float JsonObjectNode::getFloat(string key) {
        JsonFloatNode* node = dynamic_cast<JsonFloatNode*>(get(key).get());
        return (node)?node->value():0;
    }
    int JsonObjectNode::getBoolean(string key) {
        JsonBooleanNode* node = dynamic_cast<JsonBooleanNode*>(get(key).get());
        return (node)?node->value():0;
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