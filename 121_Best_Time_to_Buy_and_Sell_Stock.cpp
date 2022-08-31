#include <vector>
#include "AlgoUtils.h"

using namespace std;

class Solution {
public:
    int maxProfit(vector<int> &prices) {
        if (prices.empty()) return 0;
        int min_price = prices[0];
        int max_delta = 0;
        for (int i = 1; i < prices.size(); ++i) {
            if (min_price > prices[i]) min_price = prices[i];
            auto delta = prices[i] - min_price;
            if (delta > max_delta)  {
                max_delta = delta;
            }
        }
        return max_delta;
    }
};

class Solution_2 {
public:
    int maxProfit(vector<int> &prices) {
        if (prices.empty()) return 0;
        int min_price = prices[0];
        int max_delta = INT_MIN;
        for (auto p : prices) {
            if (p < min_price) min_price = p;
            if (max_delta < p - min_price) max_delta = p - min_price;
        }
        return max_delta;
    }
};

int main(int argc, char **argv) {
    Solution s;
    vector<int> prices_1{7, 1, 5, 3, 6, 4};
    EXPECT_EQ(s.maxProfit(prices_1), 5);
    vector<int> prices_2{7, 6, 4, 3, 1};
    EXPECT_EQ(s.maxProfit(prices_2), 0);
    vector<int> prices_3{1, 2};
    EXPECT_EQ(s.maxProfit(prices_3), 1);

    return EXIT_SUCCESS;
}