//
// Created by mincong.he on 2021/1/9.
//
#include "AlgoUtils.h"
#include <vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int> &prices) {
        auto n = prices.size();
        if (n <= 1) return 0;

        vector<vector<int>> buy(n, vector<int>(3));
        vector<vector<int>> sell(n, vector<int>(3));

        buy[0][0] = -prices[0];
        sell[0][0] = 0;

        for (int i = 1; i <= 2; ++i) {
            buy[0][i] = INT_MIN / 2;
            sell[0][i] = INT_MIN / 2;
        }

        for (int i = 1; i < n; ++i) {
            buy[i][0] = max(buy[i - 1][0], sell[i - 1][0] - prices[i]);
            for (int j = 1; j < 3; ++j) {
                buy[i][j] = max(buy[i - 1][j], sell[i - 1][j] - prices[i]);
                sell[i][j] = max(buy[i - 1][j - 1] + prices[i], sell[i - 1][j]);
            }
        }
        std::cout << std::endl;
        std::cout << "buy" << std::endl;
        printMatrix(buy);
        std::cout << std::endl;
        std::cout << "sell" << std::endl;
        printMatrix(sell);

        auto ret = *max_element(sell[n - 1].begin(), sell[n - 1].end());
        return ret < 0 ? 0 : ret;
    }
};

int main(int argc, char **argv) {
    Solution s;
    vector<int> test_case_1{3, 3, 5, 0, 0, 3, 1, 4};
    EXPECT_EQ(s.maxProfit(test_case_1), 6)
    vector<int> test_case_2{1, 2, 3, 4, 5};
    EXPECT_EQ(s.maxProfit(test_case_2), 4)
    vector<int> test_case_3{7, 6, 4, 3, 1};
    EXPECT_EQ(s.maxProfit(test_case_3), 0)
    vector<int> test_case_4{1};
    EXPECT_EQ(s.maxProfit(test_case_4), 0)
    vector<int> test_case_5{14, 9, 10, 12, 4, 8, 1, 16};
    EXPECT_EQ(s.maxProfit(test_case_5), 19)
    return EXIT_SUCCESS;
}