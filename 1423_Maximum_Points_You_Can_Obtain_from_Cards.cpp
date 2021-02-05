//
// Created by mincong.he on 2021/2/6.
//

#include "AlgoUtils.h"
#include <vector>

using namespace std;

class Solution {
public:
    int maxScore(vector<int> &cardPoints, int k) {
        auto n = cardPoints.size();
        if (n == 0) return 0;
        int sum = 0;
        for (int i = 0; i < k; ++i) {
            sum += cardPoints[i];
        }
        auto max = sum;
        for (int i = 0; i < k; ++i) {
            sum -= cardPoints[k - i - 1];
            sum += cardPoints[n - i - 1];
            if (max < sum) max = sum;
        }
        return max;
    }
};

int main(int argc, char **argv) {
    Solution s;
    vector<int> cardPoints_1 = {1, 2, 3, 4, 5, 6, 1};
    int k_1 = 3;
    EXPECT_EQ(s.maxScore(cardPoints_1, k_1), 12);

    vector<int> cardPoints_2 = {2, 2, 2};
    int k_2 = 2;
    EXPECT_EQ(s.maxScore(cardPoints_2, k_2), 4);

    vector<int> cardPoints_3 = {9, 7, 7, 9, 7, 7, 9};
    int k_3 = 7;
    EXPECT_EQ(s.maxScore(cardPoints_3, k_3), 55);

    vector<int> cardPoints_4 = {1, 1000, 1};
    int k_4 = 1;
    EXPECT_EQ(s.maxScore(cardPoints_4, k_4), 1);

    vector<int> cardPoints_5 = {1, 79, 80, 1, 1, 1, 200, 1};
    int k_5 = 3;
    EXPECT_EQ(s.maxScore(cardPoints_5, k_5), 202);
}