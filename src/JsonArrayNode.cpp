#include "JsonArrayNode.hpp"

#include <sstream>

using namespace std;

namespace json
{

    string JsonArrayNode::to_json()
    {
        stringstream ss;
        ss << "[";
        for(vector<nodeptr>::iterator i = data.begin(); i != data.end(); i++)
        {
            if(i != data.begin()) ss << ",";
            ss << (*i)->to_json();
        }
        ss << "]";
        return ss.str();
    }
    void JsonArrayNode::add(nodeptr node) {
        data.push_back(node);
    }

}