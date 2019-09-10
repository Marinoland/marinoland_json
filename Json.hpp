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
    int parse(std::string src, std::function<void(std::shared_ptr<JsonNode>)> f);
}

#endif