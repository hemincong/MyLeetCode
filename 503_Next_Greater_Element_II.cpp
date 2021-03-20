//
// Created by mincong.he on 2021/3/6.
//

#include <vector>
#include <stack>
#include "AlgoUtils.h"

using namespace std;

class Solution {
public:
    vector<int> nextGreaterElements(vector<int> &nums) {
        auto n = nums.size();
        auto res = vector(n, -1);
        stack<int> s;
        for (int i = 0; i < n * 2; ++i) {
            int num = nums[i % n];
            while (!s.empty() && nums[i % n] > nums[s.top()]) {
                res[s.top()] = num;
                s.pop();
            }

            s.push(i % n);
        }

        return res;
    }
};

int main(int argc, char **argv) {
    Solution s;
    vector<int> nums_1{1, 2, 1};
    vector<int> ret_1{2, -1, 2};
    assertArray(s.nextGreaterElements(nums_1), ret_1);
    return EXIT_SUCCESS;
}