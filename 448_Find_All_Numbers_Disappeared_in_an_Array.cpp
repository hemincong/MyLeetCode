#include "AlgoUtils.h"
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int> &nums) {
        vector<int> ret;
        auto n = nums.size();
        if (n == 0) return ret;

        for (int i = 0; i < n; ++i) {
            auto num = abs(nums[i]) - 1;
            if (nums[num] > 0) nums[num] = -nums[num];
        }

        for (int i = 0; i < n; ++i) {
            if (nums[i] > 0) ret.push_back(i + 1);
        }

        return ret;
    }
};

int main(int argc, char **argv) {
    Solution s;
    vector<int> test_case_1{4, 3, 2, 7, 8, 2, 3, 1};
    vector<int> ret_1{5, 6};
    assertArray(s.findDisappearedNumbers(test_case_1), ret_1);
    return EXIT_SUCCESS;
}