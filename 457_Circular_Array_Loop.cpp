#include <vector>
#include "AlgoUtils.h"

using namespace std;

class Solution {
public:
    bool circularArrayLoop(vector<int>& nums) {
        auto n = nums.size();
        auto next = [&](int cur) {
            return (cur + nums[cur] + n) % n;
        };
        for (int i = 0; i < n; i++) {
            int slow = i;
            int fast = next(i);
            //     同号
            while (nums[slow] * nums[fast] > 0 && nums[slow] * nums[next(fast)] > 0) {
                if (slow == fast) {
                    if (slow != next(slow)) {
                        return true;
                    }
                    break;
                }
                slow= next(slow);
                fast = next(next(fast));
            }
            int add = i;
            while (nums[add] * nums[next(add)] > 0)  {
                int tmp = add;
                add = next(add);
                nums[tmp] = 0;
            }


        }
        return false;

    }
};
int main(int argc, char **argv) {
    Solution s;
    vector<int> test_case_1{2, -1, 1, 2, 2};
    EXPECT_TRUE(s.circularArrayLoop(test_case_1));
    vector<int> test_case_2{-1, 2};
    EXPECT_FALSE(s.circularArrayLoop(test_case_2));
    vector<int> test_case_3{-2, 1, -1, -2, -2};
    EXPECT_FALSE(s.circularArrayLoop(test_case_3));
    return EXIT_SUCCESS;
}