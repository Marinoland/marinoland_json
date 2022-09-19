#include "json/ObjectNode.hpp"
#include "json/StringNode.hpp"
#include "json/IntNode.hpp"
#include "json/BooleanNode.hpp"
#include "json/FloatNode.hpp"
#include <sstream>
#include <iostream>

using namespace std;
namespace json {
    void ObjectNode::set(string key, nodeptr node) {
        values[key] = node;
    }

    nodeptr ObjectNode::get(string key) {
        stringstream ss(key);
        string word;
        ObjectNode* parentObj = this;
        nodeptr lastNode;
        do {
            getline(ss, word, '.');
            if(!parentObj || !(lastNode = parentObj->values[word]))
                return nodeptr();
            parentObj = lastNode->asObject();
        } while(!ss.eof());
        return lastNode;
    }

    string ObjectNode::getString(string key) {
        StringNode* node = dynamic_cast<StringNode*>(get(key).get());
        return (node)?node->value():"";
    }
    int ObjectNode::getInteger(string key) {
        IntNode* node = dynamic_cast<IntNode*>(get(key).get());
        return (node)?node->value():0;
    }
    float ObjectNode::getFloat(string key) {
        FloatNode* node = dynamic_cast<FloatNode*>(get(key).get());
        return (node)?node->value():0;
    }
    int ObjectNode::getBoolean(string key) {
        BooleanNode* node = dynamic_cast<BooleanNode*>(get(key).get());
        return (node)?node->value():0;
    }

    string ObjectNode::to_json() {
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