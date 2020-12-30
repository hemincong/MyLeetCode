//
// Created by mincong.he on 2020/12/30.
//

#include "AlgoUtils.h"

#include <vector>
#include <set>

using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int> &nums) {
        set<int> s;
        for (auto n : nums) {
            if (s.count(n) > 0) return true;

            s.insert(n);
        }
        return false;
    }
};

int main(int argc, char **argv) {
    Solution s;
    vector<int> test_case_1{1, 2, 3, 1};
    EXPECT_TRUE(s.containsDuplicate(test_case_1));

    vector<int> test_case_2{1, 2, 3, 4};
    EXPECT_FALSE(s.containsDuplicate(test_case_2));

    vector<int> test_case_3{1, 1, 1, 3, 3, 4, 3, 2, 4, 2};
    EXPECT_TRUE(s.containsDuplicate(test_case_3));

    return EXIT_SUCCESS;
}

