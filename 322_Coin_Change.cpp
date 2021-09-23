//
// Created by mincong.he on 2020/12/17.
//

#include <vector>
#include "AlgoUtils.h"

using namespace std;

class Solution {
public:
    int coinChange(vector<int> &coins, int amount) {
        if (amount < 1) return 0;

        vector<int> curr_change(amount + 1, -1);

        for (const auto &c : coins) {
            if (c <= amount) curr_change[c] = 1;
        }

        for (int i = 0; i <= amount; ++i) {
            int curr_min = INT_MAX;
            if (curr_change[i] > 0) curr_min = curr_change[i];
            for (const auto &c : coins) {
                const auto pos = i - c;
                if (pos < 0) continue;
                auto pos_count = curr_change[pos];

                if (pos_count > 0 && pos_count < curr_min) {
                    curr_change[i] = pos_count + 1;
                    curr_min = curr_change[i];
                }
            }
        }
        return curr_change[amount];
    }
};
class Solution_2 {
public:
    int coinChange(vector<int> &coins, int amount) {
        if (amount < 1) return 0;

        vector<int> curr_change(amount + 1, -1);

        for (const auto &c: coins) {
            if (c <= amount) curr_change[c] = 1;
        }

        for (int i = 0; i <= amount; i++) {
            int min_amount = INT_MAX;
            // 如果就在coins里面小心被冲掉
            if (curr_change[i] > 0) min_amount = curr_change[i];
            for (const auto &c: coins) {
                const int pos = i - c;

                if (pos > 0 && curr_change[pos] > 0 && min_amount > curr_change[pos] + 1) {
                    min_amount = curr_change[pos] + 1;
                }
            }
            if (min_amount != INT_MAX) curr_change[i] = min_amount;
        }

        return curr_change[amount];
    }
};
int main(int argc, char **argv) {
    Solution s;

    vector<int> cons_0{2};
    EXPECT_EQ(s.coinChange(cons_0, 1), -1);

    vector<int> cons_1{1, 2, 5};
    EXPECT_EQ(s.coinChange(cons_1, 11), 3);

    vector<int> cons_2{2};
    EXPECT_EQ(s.coinChange(cons_2, 3), -1);

    vector<int> cons_3{1};
    EXPECT_EQ(s.coinChange(cons_3, 0), 0);

    vector<int> cons_4{1};
    EXPECT_EQ(s.coinChange(cons_4, 1), 1);

    vector<int> cons_5{1};
    EXPECT_EQ(s.coinChange(cons_5, 2), 2);

    vector<int> cons_6{1, 2, 5, 7, 10};
    EXPECT_EQ(s.coinChange(cons_6, 14), 2);

    vector<int> cons_7{474, 83, 404, 3};
    EXPECT_EQ(s.coinChange(cons_7, 264), 8);

    return EXIT_SUCCESS;
}
