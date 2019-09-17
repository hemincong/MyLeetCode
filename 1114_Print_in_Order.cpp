#include <string>
#include <vector>
#include <stdio.h>
#include <functional>
#include <sstream>
#include <iostream>

using namespace std;

class Foo {
public:
    Foo() {

    }

    void first(function<void()> printFirst) {

        // printFirst() outputs "first". Do not change or remove this line.
        printFirst();
    }

    void second(function<void()> printSecond) {

        // printSecond() outputs "second". Do not change or remove this line.
        printSecond();
    }

    void third(function<void()> printThird) {

        // printThird() outputs "third". Do not change or remove this line.
        printThird();
    }
};

void trimLeftTrailingSpaces(string &input) {
    input.erase(input.begin(), find_if(input.begin(), input.end(), [](int ch) {
        return !isspace(ch);
    }));
}

void trimRightTrailingSpaces(string &input) {
    input.erase(find_if(input.rbegin(), input.rend(), [](int ch) {
        return !isspace(ch);
    }).base(), input.end());
}

vector<int> stringToIntegerVector(string input) {
    vector<int> output;
    trimLeftTrailingSpaces(input);
    trimRightTrailingSpaces(input);
    input = input.substr(1, input.length() - 2);
    stringstream ss;
    ss.str(input);
    string item;
    char delim = ',';
    while (getline(ss, item, delim)) {
        output.push_back(stoi(item));
    }
    return output;
}

int main() {
    string line;
    while (getline(cin, line)) {
        vector<int> nums = stringToIntegerVector(line);

        int ret = Solution().foobar(nums);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
