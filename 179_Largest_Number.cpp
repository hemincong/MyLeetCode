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
        auto n = nums.size();
        if (n == 0) return "";

        vector<string> tmp;
        tmp.reserve(nums.size());
        for (const auto &i : nums) {
            tmp.push_back(std::to_string(i));
        }
        sort(tmp.begin(), tmp.end(), [](const string &s1, const string &s2) {
            return s1 + s2 > s2 + s1;
        });
        if (tmp[0] == "0") return "0";
        std::stringstream ss;
        for (const auto &i : tmp) {
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