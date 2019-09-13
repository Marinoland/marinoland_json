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

add_executable(sample sample.cpp)
target_link_libraries(sample LINK_PUBLIC json)