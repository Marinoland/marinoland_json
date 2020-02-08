#ifndef __JSONNODE_HPP__
#define __JSONNODE_HPP__

#include <string>
#include <memory>
#include <functional>

namespace json {
    class JsonArrayNode;
    typedef std::function<void(JsonArrayNode & node)> arrayCast;
    class JsonObjectNode;
    typedef std::function<void(JsonObjectNode & node)> objectCast;
    
    class JsonNode {
    public:
        virtual std::string to_string() { return to_json(); }
        virtual std::string to_json() { return ""; }
        virtual void asArray(arrayCast fn){};
        virtual void asObject(objectCast fn){};
    private:
    };
    typedef std::shared_ptr<JsonNode> nodeptr;
}


#endif