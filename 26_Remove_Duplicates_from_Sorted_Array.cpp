//
// Created by mincong.he on 2021/4/18.
//

#include <vector>
#include "AlgoUtils.h"

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int> &nums) {
        auto n = nums.size();
        if (n == 1) return 1;

        int i = 0;
        int j = 0;
        int p = i + 1;
        while (p < n) {
            p = i + 1;
            while (p < n && nums[p] == nums[i]) {
                p++;
            }

            nums[j] = nums[i];
            i = p;
            j++;
        }
        nums.resize(j);
        return j;
    }
};


int main(int argc, char **argv) {
    Solution s;
    vector<int> test_case_0{1};
    vector<int> ret_0{1};
    EXPECT_EQ(s.removeDuplicates(test_case_0), 1);
    assertArray(test_case_0, ret_0);

    vector<int> test_case_0_1{1, 2, 3};
    vector<int> ret_0_1{1, 2, 3};
    EXPECT_EQ(s.removeDuplicates(test_case_0_1), 3);
    assertArray(test_case_0_1, ret_0_1);

    vector<int> test_case_0_2{1, 1};
    vector<int> ret_0_2{1};
    EXPECT_EQ(s.removeDuplicates(test_case_0_2), 1);
    assertArray(test_case_0_2, ret_0_2);

    vector<int> test_case_1{1, 1, 2};
    vector<int> ret_1{1, 2};
    EXPECT_EQ(s.removeDuplicates(test_case_1), 2);
    assertArray(test_case_1, ret_1);

    vector<int> test_case_2{0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
    vector<int> ret_2{0, 1, 2, 3, 4};
    EXPECT_EQ(s.removeDuplicates(test_case_2), 5);
    assertArray(test_case_2, ret_2);

    return EXIT_SUCCESS;
}