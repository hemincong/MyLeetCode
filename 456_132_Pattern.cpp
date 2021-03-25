//
// Created by mincong.he on 2021/3/24.
//

#include <vector>
#include "AlgoUtils.h"

using namespace std;

class Solution {
public:
    bool find132pattern(vector<int> &nums) {
        auto n = nums.size();
        if (n < 3) return false;
        stack<int> s;
        // k 维护的是2
        int k = INT_MIN;
        for (int i = n - 1; i >= 0; --i) {
            // nums[i] < k就是1
            if (nums[i] < k) return true;
            // 栈顶是3
            while (!s.empty() && s.top() < nums[i]) {
                k = s.top();
                s.pop();
            }
            s.push(nums[i]);
        }
        return false;
    }
};

int main(int argc, char **argv) {
    Solution s;
    vector<int> test_case_1{1, 2, 3, 4};
    vector<int> test_case_2{3, 1, 4, 2};
    vector<int> test_case_3{-1, 3, 2, 0};
    vector<int> test_case_75{1, 0, 1, -4, -3};

    EXPECT_FALSE(s.find132pattern(test_case_1));
    EXPECT_TRUE(s.find132pattern(test_case_2));
    EXPECT_TRUE(s.find132pattern(test_case_3));
    EXPECT_FALSE(s.find132pattern(test_case_75));
    return EXIT_SUCCESS;
}