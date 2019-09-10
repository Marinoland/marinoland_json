#include "Json.hpp"

using namespace std;


namespace json {

    void skipwhitespace(char *c, function<void(char *c)> f) {
        char *result = c;
        while(*result == ' ' || *result == '\t' ||
            *result == '\n' || *result == '\r') result++;
        f(result);
    }

    int try_boolean(char *c, function<void(char *c, std::string b)>) {

//TODO bool detect

    }

    int parse(string src, function<void(shared_ptr<JsonNode>)> f) {



        return 0;
    }
}