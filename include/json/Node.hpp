#pragma once

#include <string>
#include <memory>
#include <functional>

namespace json {
    //deprecated
    class ArrayNode;
    typedef std::function<void(ArrayNode & node)> arrayCast;
    //deprecated
    class ObjectNode;
    typedef std::function<void(ObjectNode & node)> objectCast;
    
    class Node {
    public:
        virtual std::string to_string() { return to_json(); }
        virtual std::string to_json() { return ""; }
        //deprecated
        virtual void asArray(arrayCast fn){};
        //deprecated
        virtual void asObject(objectCast fn){};
        virtual ArrayNode* asArray(){ return 0; };
        virtual ObjectNode* asObject(){ return 0; };
    private:
    };
    typedef std::shared_ptr<Node> nodeptr;
}
