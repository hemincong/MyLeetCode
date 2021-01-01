//
// Created by mincong.he on 2021/1/2.
//

#include "AlgoUtils.h"

#include <vector>

using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k) {
        auto n = nums.size();
        priority_queue<pair<int, int>> slide_window;
        for (int i = 0; i < k; ++i) {
            slide_window.emplace(nums[i], i);
        }
        vector<int> ret;
        ret.emplace_back(slide_window.top().first);
        for (int i = k; i < n; ++i) {
            slide_window.emplace(nums[i], i);
            while (slide_window.top().second <= i - k) {
                slide_window.pop();
            }
            ret.emplace_back(slide_window.top().first);
        }
        return ret;
    }
};

int main(int argc, char **argv) {
    Solution s;
    vector<int> test_case_1{1, 3, -1, -3, 5, 3, 6, 7}; // [3,3,5,5,6,7]
    auto ret = s.maxSlidingWindow(test_case_1, 3);
    printArray(ret);

    vector<int> test_case_2{1}; // [1]
    ret = s.maxSlidingWindow(test_case_2, 1);
    printArray(ret);

    vector<int> test_case_3{1, -1}; // [1, -1]
    ret = s.maxSlidingWindow(test_case_3, 1);
    printArray(ret);

    vector<int> test_case_4{9, 11}; // [11]
    ret = s.maxSlidingWindow(test_case_4, 2);
    printArray(ret);

    vector<int> test_case_5{4, -2}; // [4]
    ret = s.maxSlidingWindow(test_case_5, 2);
    printArray(ret);

    vector<int> test_case_6{9, 10, 9, -7, -4, -8, 2, -6}; // [10, 10, 9, 2]
    ret = s.maxSlidingWindow(test_case_6, 5);
    printArray(ret);

    return EXIT_SUCCESS;
}