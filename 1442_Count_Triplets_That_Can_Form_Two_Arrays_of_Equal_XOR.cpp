//
// Created by mincong.he on 2021/5/18.
//

#include <vector>
#include "AlgoUtils.h"

using namespace std;

class Solution {
public:
    int countTriplets(vector<int> &arr) {
        auto n = arr.size();
        int ret = 0;

        for (int i = 0; i < n - 1; ++i) {
            int sum = 0;
            for (int j = i; j < n; ++j) {
                sum ^= arr[j];
                if (sum == 0 && j > i) ret += (j - i);
            }
        }
        return ret;
    }
};

int main(int argc, char **argv) {
    Solution s;
    vector<int> test_case_1{2, 3, 1, 6, 7};
    EXPECT_EQ(s.countTriplets(test_case_1), 4);

    vector<int> test_case_2{1, 1, 1, 1, 1};
    EXPECT_EQ(s.countTriplets(test_case_2), 10);

    vector<int> test_case_3{2, 3};
    EXPECT_EQ(s.countTriplets(test_case_3), 0);

    vector<int> test_case_4{1, 3, 5, 7, 9};
    EXPECT_EQ(s.countTriplets(test_case_4), 3);

    vector<int> test_case_5{7, 11, 12, 9, 5, 2, 7, 17, 22};
    EXPECT_EQ(s.countTriplets(test_case_5), 8);

    return EXIT_SUCCESS;
}