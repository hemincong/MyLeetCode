//
// Created by mincong.he on 2021/1/25.
//

#include <vector>
#include <string>
#include <sstream>

#include "AlgoUtils.h"

using namespace std;

class Solution {
public:
    string largestNumber(vector<int> &nums) {
        if (nums.empty()) return "";

        vector<string> tmp_str;
        tmp_str.reserve(nums.size());
        for (auto i : nums) {
            tmp_str.emplace_back(std::to_string(i));
        }
        std::sort(tmp_str.begin(), tmp_str.end(), [](const string &s1, const string &s2) {
            return s1 + s2 > s2 + s1;
        });
        // 0都能做老大，其实没其他数小了
        if (tmp_str[0] == "0") return "0";

        stringstream ss;
        for (auto &i : tmp_str) {
            ss << i;
        }
        return ss.str();
    }
};

int main(int argc, char **argv) {
    Solution s;
    vector<int> test_case_0{0, 0};
    EXPECT_EQ(s.largestNumber(test_case_0), "0");

    vector<int> test_case_1{10, 2};
    EXPECT_EQ(s.largestNumber(test_case_1), "210");

    vector<int> test_case_2{3, 30, 34, 5, 9};
    EXPECT_EQ(s.largestNumber(test_case_2), "9534330");

    vector<int> test_case_3{1};
    EXPECT_EQ(s.largestNumber(test_case_3), "1");
    return EXIT_SUCCESS;
}