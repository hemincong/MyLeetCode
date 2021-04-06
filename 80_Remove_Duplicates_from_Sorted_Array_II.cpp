//
// Created by mincong.he on 2021/4/6.
//
#include <vector>
#include "AlgoUtils.h"

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int> &nums) {
        auto n = nums.size();
        if (n <= 2) return n;

        int p = 0;
        int i = 0;
        int j = 1;
        while (j < n) {
            j = i + 1;
            while (j < n && nums[i] == nums[j]) {
                j++;
            }
            nums[p++] = nums[i];
            if (j - i >= 2) {
                nums[p++] = nums[i];
            }
            i = j;
        }
        nums.resize(p);
        return p;
    }
};

int main(int argc, char **argv) {
    Solution s;
    vector<int> test_case_1{1, 1, 1, 2, 2, 3};
    vector<int> ret_1{1, 1, 2, 2, 3};
    EXPECT_EQ(s.removeDuplicates(test_case_1), 5);
    assertArray(test_case_1, ret_1);

    vector<int> test_case_2{0, 0, 1, 1, 1, 1, 2, 3, 3};
    vector<int> ret_2{0, 0, 1, 1, 2, 3, 3};
    EXPECT_EQ(s.removeDuplicates(test_case_2), 7);
    assertArray(test_case_2, ret_2);

    vector<int> test_case_3{1, 1};
    vector<int> ret_3{1, 1};
    EXPECT_EQ(s.removeDuplicates(test_case_3), 2);
    assertArray(test_case_3, ret_3);

    vector<int> test_case_4{0, 0, 1, 1, 1, 1, 2, 3, 3, 3};
    vector<int> ret_4{0, 0, 1, 1, 2, 3, 3};
    EXPECT_EQ(s.removeDuplicates(test_case_4), 7);
    assertArray(test_case_4, ret_4);

    vector<int> test_case_5{1, 1, 1, 1};
    vector<int> ret_5{1, 1};
    EXPECT_EQ(s.removeDuplicates(test_case_5), 2);
    assertArray(test_case_5, ret_5);
}