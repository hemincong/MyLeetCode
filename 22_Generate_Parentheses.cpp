//
// Created by mincong.he on 2019/10/29.
//

#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        std::string vc;
        std::vector<std::string> r;
        int i = 0;
        gen("", n, 0, 0, r);
        return r;
    }

private:
    static void gen(const std::string &item, int n, int left, int right, std::vector<std::string> &result) {
        // i 记录可能push的个数
        if (right == n && left == n) {
            result.push_back(item);
            return;
        }

        if (left < n) {
            gen(item + '(', n, left + 1, right, result);
        }

        if (left > right) {
            gen(item + ')', n, left, right + 1, result);
        }
    }
};

int main(int argc, char **argv) {
    Solution solution;
    auto s = solution.generateParenthesis(3);
    std::cout << "[";
    for (const auto &i : s) {
        std::cout << "\"" << i << "\",";
    }
    std::cout << "]";
}