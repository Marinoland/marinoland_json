#pragma once

#include "json/Node.hpp"
#include <string>
#include <vector>
#include <map>

namespace json {
    using namespace std;
    class ObjectNode : public Node {
    public: 
        void set(string key, nodeptr);
        nodeptr get(string key);
        string getString(string key);
        int getInteger(string key);
        float getFloat(string key);
        int getBoolean(string key);
        //deprecated
        virtual void asObject(objectCast fn){fn(*this);};
        virtual ObjectNode* asObject(){ return this; };
        string to_json();
        vector<string> getKeys() {
            vector<string> ret;
            for(pair<string, nodeptr> p : values) {
                ret.push_back(p.first);
            }
            return ret;
        }
    private:
        map<string, nodeptr> values;
    };
}