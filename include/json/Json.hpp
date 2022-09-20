#pragma once

#include <string>
#include <memory>
#include <functional>
#include "json/NullNode.hpp"
#include "json/IntNode.hpp"
#include "json/FloatNode.hpp"
#include "json/BooleanNode.hpp"
#include "json/StringNode.hpp"
#include "json/ArrayNode.hpp"
#include "json/ObjectNode.hpp"

namespace json {
    void parse(std::string src, std::function<void(nodeptr)> f, std::function<void(std::string)> e);
    void fromFile(std::string filename, std::function<void(nodeptr)> f, std::function<void(std::string)> e);
}
