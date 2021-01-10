//
// Created by mincong.he on 2021/1/10.
//

#include <string>
#include <vector>
#include "AlgoUtils.h"

using namespace std;

char buff[255];

class Solution {
public:
    vector<string> summaryRanges(vector<int> &nums) {
        vector<string> ret;
        if (nums.empty()) return ret;

        auto n = nums.size();
        int begin = 0;
        int end = begin;
        while (begin < n) {
            while (end + 1 < n && nums[end] == nums[end + 1] - 1) {
                end++;
            }
            if (end == begin) {
                ret.push_back(std::to_string(nums[end]));
            } else {
                memset(buff, '\0', 255);
                sprintf(buff, "%d->%d", nums[begin], nums[end]);
                ret.emplace_back(string(buff));
            }
            begin = end + 1;
            end = begin;
        }

        return ret;
    }
};

int main(int argc, char **argv) {
    Solution s;
    vector<int> test_case_1{0, 1, 2, 4, 5, 7};
    printArray(s.summaryRanges(test_case_1));
    std::cout << std::endl;
    vector<int> test_case_2{0, 2, 3, 4, 6, 8, 9};
    printArray(s.summaryRanges(test_case_2));
    std::cout << std::endl;
    vector<int> test_case_3{-2147483648, -2147483647, 2147483647};
    printArray(s.summaryRanges(test_case_3));
    std::cout << std::endl;
    vector<int> test_case_4;
    printArray(s.summaryRanges(test_case_4));
    std::cout << std::endl;
    vector<int> test_case_5{-1};
    printArray(s.summaryRanges(test_case_5));

    return EXIT_SUCCESS;
}