//
// Created by mincong.he on 2021/4/19.
//

//
// Created by mincong.he on 2021/4/18.
//

#include <vector>
#include "AlgoUtils.h"

using namespace std;

class Solution {
public:
    int removeElement(vector<int> &nums, int val) {
        auto n = nums.size();
        int j = 0;
        for (int i = 0; i < n; ++i) {
            if (nums[i] != val) {
                nums[j] = nums[i];
                j++;
            }
        }
        nums.resize(j);
        return j;
    }
};


int main(int argc, char **argv) {
    Solution s;
    vector<int> test_case_1{3, 2, 2, 3};
    vector<int> ret_1{2, 2};
    EXPECT_EQ(s.removeElement(test_case_1, 3), 2);
    assertArray(test_case_1, ret_1);

    vector<int> test_case_2{0, 1, 2, 2, 3, 0, 4, 2};
    vector<int> ret_2{0, 1, 4, 0, 3};
    EXPECT_EQ(s.removeElement(test_case_2, 2), 5);
    assertArray(test_case_2, ret_2);

    vector<int> test_case_3{3, 2, 2, 3};
    vector<int> ret_3{3, 2, 2, 3};
    EXPECT_EQ(s.removeElement(test_case_3, 4), 4);
    assertArray(test_case_3, ret_3);

    return EXIT_SUCCESS;
}