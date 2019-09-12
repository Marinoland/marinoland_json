#ifndef __JSON_HPP__
#define __JSON_HPP__

#include <string>
#include <memory>
#include <functional>
#include "JsonNullNode.hpp"
#include "JsonIntNode.hpp"
#include "JsonFloatNode.hpp"
#include "JsonBooleanNode.hpp"
#include "JsonStringNode.hpp"
#include "JsonArrayNode.hpp"
#include "JsonObjectNode.hpp"

namespace json {
    void parse(std::string src, std::function<void(nodeptr)> f, std::function<void(std::string)> e);
}

#endif