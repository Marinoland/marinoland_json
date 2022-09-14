#pragma once

#include "json/Node.hpp"

namespace json {
    
    class NullNode : public Node {
    public: 
        std::string to_json();
    private:
    };
}
