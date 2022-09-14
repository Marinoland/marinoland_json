cmake_minimum_required(VERSION 2.8)
project (json)

include_directories(
    /usr/include
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

IF (WIN32)
    add_definitions(-D_WIN32_WINNT=0x0601)
ELSE()
    add_definitions(-std=c++11)
ENDIF()


add_library(json STATIC
    src/Json.cpp
    src/ArrayNode.cpp
    src/BooleanNode.cpp
    src/FloatNode.cpp
    src/IntNode.cpp
    src/Node.cpp
    src/NullNode.cpp
    src/ObjectNode.cpp
    src/StringNode.cpp)

add_executable(test test/test.cpp)
link_directories(${CMAKE_CURRENT_BINARY_DIR})
target_link_libraries(test LINK_PUBLIC json)

execute_process(COMMAND ${CMAKE_CURRENT_BINARY_DIR}/test)
