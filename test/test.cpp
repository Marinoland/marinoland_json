#include <iostream>
#include <vector>
#include <sstream>

#include "Json.hpp"

using namespace std;

int main(int argc, char **argv)
{
    vector<string> things_to_parse = {
        "null",
        "false",
        "true",
        "\" should fail",
        " [\"test\", [700, \"bl\\\"ah\\n\\\\blah\" ], true, false, [null, 0.4 ]]",
        "{\"blah\": \"test\"}",
        "{\"arr\": [], \"arr2\":[ 2, {},]}"
    };
    vector<string> expected = {
        "null",
        "false",
        "true",
        "Unexpected end of file while reading string : at position 13",
        "[\"test\",[700,\"bl\\\"ah\\n\\\\blah\"],true,false,[null,0.400000]]",
        "{\"blah\":\"test\"}",
        "{\"arr\":[],\"arr2\":[2,{}]}"
    };
    for(int i = 0; i < things_to_parse.size(); i++)
    {
        string try_this = things_to_parse[i];
        string expectedText = expected[i];
        string resultText;
        json::parse(try_this,
            [&] (json::nodeptr node) { resultText = node->to_string(); },
            [&] (string msg) { resultText = msg; });
        if(expectedText == resultText) {
            cout << "PASSED" << endl;
        } else {
            cerr << "FAILED. Expected (" << expectedText << ") Got (" << resultText << ")" << endl;
        }
    }

    json::parse("[1, 2, 3]",
        [&] (json::nodeptr node) {
            json::JsonArrayNode & arr = *(json::JsonArrayNode*)node.get();
            stringstream strstr("");
            for (json::nodeptr node : arr) {
                strstr << node->to_string();
            }
            if(strstr.str() == "123") {
                cout << "PASSED" << endl;
            } else {
                cerr << "FAILED. Expected (123) Got (" << strstr.str() << ")" << endl;
            }
        },
        [&] (string msg) {
            cerr << "FAILED. " + msg << endl;
        });
    return 0;
}