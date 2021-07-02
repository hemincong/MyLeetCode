//
// Created by mincong.he on 2021/7/2.
//

#include <vector>
#include "AlgoUtils.h"

using namespace std;

class Solution {
public:
    int maxIceCream(vector<int> &costs, int coins) {
        std::sort(costs.begin(), costs.end(), std::less<>());

        int count = 0;
        for (int cost : costs) {
            if (cost <= coins) {
                coins -= cost;
                count++;
            } else return count;
        }
        return count;
    }
};

int main(int argc, char **argv) {
    Solution s;
    auto test_case_1 = vector<int>{1, 3, 2, 4, 1};
    EXPECT_EQ(s.maxIceCream(test_case_1, 7), 4);
    auto test_case_2 = vector<int>{10, 6, 8, 7, 7, 8};
    EXPECT_EQ(s.maxIceCream(test_case_2, 5), 0);
    auto test_case_3 = vector<int>{1, 6, 3, 1, 2, 5};
    EXPECT_EQ(s.maxIceCream(test_case_3, 20), 6);
    return EXIT_SUCCESS;

}