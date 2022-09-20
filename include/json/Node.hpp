#pragma once

#include <string>
#include <memory>
#include <functional>

namespace json {

    using namespace std;
    //deprecated
    class ArrayNode;
    typedef function<void(ArrayNode & node)> arrayCast;
    //deprecated
    class ObjectNode;
    typedef function<void(ObjectNode & node)> objectCast;
    
    class Node {
    public:
        virtual string to_string() { return to_json(); }
        virtual string to_json() { return ""; }
        virtual string getString(string key) { return "";}
        virtual int getInteger(string key) { return 0;}
        virtual float getFloat(string key) { return 0;}
        virtual int getBoolean(string key) { return 0;}
        //deprecated
        virtual void asArray(arrayCast fn){};
        //deprecated
        virtual void asObject(objectCast fn){};
        virtual ArrayNode* asArray(){ return 0; };
        virtual ObjectNode* asObject(){ return 0; };
    private:
    };
    typedef shared_ptr<Node> nodeptr;
}
