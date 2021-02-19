//
// Created by mincong.he on 2021/2/18.
//

#include <vector>
#include "AlgoUtils.h"

using namespace std;

class Solution {
public:
    int minKBitFlips(vector<int> &A, int K) {
        auto n = A.size();
        if (n < K) return -1;
        int count = 0;
        int curr_count = 0;

        vector<int> diff(n + 1, 0);
        for (int i = 0; i < A.size(); ++i) {
            curr_count += diff[i];
            if ((curr_count + A[i]) % 2 == 0) {
                if (i + K > n) return -1;
                count++;
                curr_count++;
                diff[i + K]--;
            }
        }

        return count;
    }
};

int main(int argc, char **argv) {
    Solution s;
    vector<int> test_case_1{0, 1, 0};
    EXPECT_EQ(s.minKBitFlips(test_case_1, 1), 2);

    vector<int> test_case_2{1, 1, 0};
    EXPECT_EQ(s.minKBitFlips(test_case_2, 2), -1);

    vector<int> test_case_3{0, 0, 0, 1, 0, 1, 1, 0};
    EXPECT_EQ(s.minKBitFlips(test_case_3, 3), 3);
    return EXIT_SUCCESS;
}