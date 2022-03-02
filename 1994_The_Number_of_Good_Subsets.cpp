//
// Created by mincong.he on 2022/2/22.
//

#include <vector>
#include "AlgoUtils.h"

using namespace std;

const static long MOD = 1e9 + 7;
const static int p[10] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};

class Solution {
public:
    int numberOfGoodSubsets(vector<int> &nums) {
        vector<int> count(31);
        for (auto n: nums) {
            count[n]++;
        }
        int total = 1 << 10;
        vector<long long> dp(total);
        dp[0] = 1;
        for (int num = 2; num < 31; num++) {
            if (count[num] == 0) continue;
            int temp = num;
            int use = 0;
            bool flag = true;
            for (int i = 0; i < 10; ++i) {
                int cnt = 0;
                while (temp % p[i] == 0) {
                    cnt++;
                    use |= 1 << i;
                    temp /= p[i];
                }
                // 被多一个质数整除
                if (cnt > 1) {
                    flag = false;
                    break;
                }
            }
            if (!flag) continue;
            for (int set = 0; set < total; set++) {
                if ((set & use) == 0) {
                    dp[set | use] = (dp[set | use] + dp[set] * count[num]) % MOD;
                }
            }
        }
        long long res = 0;
        for (int i = 1; i < total; i++) {
            res = (res + dp[i]) % MOD;
        }
        for (int i = 0; i < count[1]; i++) {
            res = res * 2 % MOD;
        }
        return (int) res;
    }
};

int main(int argc, char **argv) {
    Solution s;
    vector<int> test_case_1{1, 2, 3, 4};
    EXPECT_EQ(s.numberOfGoodSubsets(test_case_1), 6);
    vector<int> test_case_2{4, 2, 3, 15};
    EXPECT_EQ(s.numberOfGoodSubsets(test_case_2), 5);
    return EXIT_SUCCESS;
}