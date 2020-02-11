cmake_minimum_required(VERSION 2.8)
project (json)


include_directories(/usr/include)
add_definitions(-std=c++11)
add_library(json STATIC
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
if(WIN32)
    link_directories(${CMAKE_CURRENT_SOURCE_DIR}/Release)
endif()
target_link_libraries(test LINK_PUBLIC json)
