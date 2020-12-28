//
// Created by mincong.he on 2020/12/28.
//
#include "AlgoUtils.h"

#include <vector>

using namespace std;

class Solution {
public:
    int maxProfit(int k, vector<int> &prices) {
        if (prices.empty()) return 0;
        auto n = prices.size();
        if (k > n / 2) k = n / 2;

        vector<vector<int>> buy(n, vector<int>(k + 1));
        vector<vector<int>> sell(n, vector<int>(k + 1));

        buy[0][0] = -prices[0];
        sell[0][0] = 0;

        for (int i = 1; i <= k; ++i) {
            buy[0][i] = INT_MIN / 2;
            sell[0][i] = INT_MIN / 2;
        }

        for (int i = 1; i < n; ++i) {
            buy[i][0] = max(buy[i - 1][0], sell[i - 1][0] - prices[i]);
            for (int j = 1; j <= k; ++j) {
                buy[i][j] = max(buy[i - 1][j], sell[i - 1][j] - prices[i]);
                sell[i][j] = max(buy[i - 1][j - 1] + prices[i], sell[i - 1][j]);
            }
        }

        return *max_element(sell[n - 1].begin(), sell[n - 1].end());
    }
};

int main(int argc, char **argv) {
    Solution s;
    vector<int> test_case_1{2, 4, 1};
    EXPECT_EQ(s.maxProfit(2, test_case_1), 2);
    vector<int> test_case_2{3, 2, 6, 5, 0, 3};
    EXPECT_EQ(s.maxProfit(2, test_case_2), 7);
    return EXIT_SUCCESS;
}
