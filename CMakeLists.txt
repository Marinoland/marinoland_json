cmake_minimum_required(VERSION 2.8)
project (json)


include_directories(/usr/include)
add_definitions(-std=c++11)
add_library(json SHARED
    Json.cpp
    JsonArrayNode.cpp
    JsonBooleanNode.cpp
    JsonFloatNode.cpp
    JsonIntNode.cpp
    JsonNode.cpp
    JsonNullNode.cpp
    JsonObjectNode.cpp
    JsonStringNode.cpp)

add_executable(test test.cpp)
target_link_libraries(test LINK_PUBLIC json)
