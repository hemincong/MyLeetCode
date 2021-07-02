//
// Created by mincong.he on 2021/7/2.
//

#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

class Solution {
public:
    string replaceSpace(string s) {
        if (s.empty()) return "";
        std::vector<char> v;
        v.reserve(s.size() + 10);
        for (auto &c: s) {
            if (c != ' ') {
                v.push_back(c);
            } else {
                v.push_back('%');
                v.push_back('2');
                v.push_back('0');
            }
        }
        v.push_back('\0');
        return string((const char *) &v.at(0));
    }
};

int main(int argc, char **argv) {
    Solution s;
    std::cout << s.replaceSpace("We are happy.") << std::endl;
    return EXIT_SUCCESS;

}