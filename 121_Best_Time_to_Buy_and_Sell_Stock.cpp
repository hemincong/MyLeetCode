#include <vector>
#include "AlgoUtils.h"

using namespace std;

class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int n = prices.size();
        int min_prices = prices[0];
        int ret = 0;
        for (int i = 1; i < n; ++i) {
            if (min_prices > prices[i]) {
                min_prices = prices[i];
            }
            auto temp = prices[i] - min_prices;
            ret = max(ret, temp);
        }
        return ret;
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