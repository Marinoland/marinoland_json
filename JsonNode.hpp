#ifndef __JSONNODE_HPP__
#define __JSONNODE_HPP__

#include <string>
#include <memory>

namespace json {
    class JsonNode {
    public:
        virtual std::string to_string() { return ""; }
    private:
    };
    typedef std::shared_ptr<JsonNode> nodeptr;
}


#endif