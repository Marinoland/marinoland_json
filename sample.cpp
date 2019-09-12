#include <iostream>
#include <vector>

#include "Json.hpp"

using namespace std;

int main(int argc, char **argv)
{

    vector<string> things_to_try = {
        "null",
        "false",
        "true",
        "\" should fail",
        " [\"test\", [700, \"bl\\\"ah\\n\\\\blah\" ], true, false, [null, 0.4 ]]"
    };
    for(string try_this : things_to_try)
    {
        json::parse(try_this,
        [] (json::nodeptr node)
        {
            cout << node->to_string() << endl;
        },
        [] (string msg)
        {
            cerr << msg << endl;
        });
    }
    return 0;
}