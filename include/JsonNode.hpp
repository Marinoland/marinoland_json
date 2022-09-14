#ifndef __JSONNODE_HPP__
#define __JSONNODE_HPP__

#include <string>
#include <memory>
#include <functional>

namespace json {
    //deprecated
    class JsonArrayNode;
    typedef std::function<void(JsonArrayNode & node)> arrayCast;
    //deprecated
    class JsonObjectNode;
    typedef std::function<void(JsonObjectNode & node)> objectCast;
    
    class JsonNode {
    public:
        virtual std::string to_string() { return to_json(); }
        virtual std::string to_json() { return ""; }
        //deprecated
        virtual void asArray(arrayCast fn){};
        //deprecated
        virtual void asObject(objectCast fn){};
        virtual JsonArrayNode* asArray(){ return 0; };
        virtual JsonObjectNode* asObject(){ return 0; };
    private:
    };
    typedef std::shared_ptr<JsonNode> nodeptr;
}


#endif