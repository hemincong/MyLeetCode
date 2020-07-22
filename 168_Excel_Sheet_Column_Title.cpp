//
// Created by mincong.he on 2020/7/22.
//

#include <string>
#include <stack>
#include "AlgoUtils.h"

using namespace std;

class Solution {
public:
    string convertToTitle(int n) {
        if (n == 0) return "";

        stack<char> s;
        while (n > 0) {
            n--;
            auto r = n % 26;
            s.push('A' + r);
            n = n / 26;
        }

        vector<char> r_vec;
        while (!s.empty()) {
            r_vec.push_back(s.top());
            s.pop();
        }
        r_vec.push_back('\0');
        return string(&r_vec.at(0));
    }
};

int main(int argc, char **argv) {
    Solution s;
    std::cout << s.convertToTitle(0) << std::endl;
    std::cout << s.convertToTitle(1) << std::endl;
    std::cout << s.convertToTitle(28) << std::endl;
    std::cout << s.convertToTitle(701) << std::endl;
    return EXIT_SUCCESS;
}