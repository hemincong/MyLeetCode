//
// Created by mincong.he on 2021/2/3.
//

#include "AlgoUtils.h"
#include <vector>

using namespace std;

class Solution {
public:
    vector<double> medianSlidingWindow(vector<int> &nums, int k) {
        vector<double> ret;
        std::priority_queue<int, vector<int>, less<int>> big_heap;
        std::priority_queue<int, vector<int>, greater<int>> small_heap;
        int median;

        for (int i = 0; i < k; ++i) {
            big_heap.push(nums[i]);
        }
        for (int i = 0; i < k / 2; ++i) {
            auto top = big_heap.top();
            small_heap.push(top);
            big_heap.pop();
        }

        median = big_heap.top();
        ret.push_back(median);

        auto n = nums.size();
        for (int i = 0; i < n - k - 1; ++i) {
            auto x = nums[i+k];
            auto remove = nums[i];
            if (x < median) {
                auto big_top = big_heap.top();
                small_heap.push(median);
                median = big_top;
                big_heap.push(x);
            } else {
                auto small_top = small_heap.top();
                big_heap.push(median);
                median = small_top;
                small_heap.push(x);
            }
            ret.push_back(median);
        }
        return ret;
    }
};

int main(int argc, char **argv) {
    Solution s;
    vector<int> test_case_1{1, 3, -1, -3, 5, 3, 6, 7};
    vector<double> ret_1{1, -1, -1, 3, 5, 6};
    assertArray(s.medianSlidingWindow(test_case_1, 3), ret_1);
    return EXIT_SUCCESS;
}