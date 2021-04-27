//
// Created by mincong.he on 2021/4/27.
//

#include <vector>
#include <numeric>
#include "AlgoUtils.h"

using namespace std;

class Solution {
public:
    int shipWithinDays(vector<int> &weights, int D) {
        auto max = *std::max_element(weights.begin(), weights.end());
        auto sum = std::accumulate(weights.begin(), weights.end(), 0);
        auto left = max;
        auto right = sum;
        while (left < right) {
            auto mid = left + ((right - left) >> 1);
            if (check(weights, D, mid)) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }

private:
    static bool check(const vector<int> &weights, int D, int w) {
        int count = 1;
        int temp = 0;
        for (int weight : weights) {
            temp += weight;
            if (temp > w) {
                temp = weight;
                count++;
            }
            if (count > D) return false;
        }
        return true;
    }
};

int main(int argc, char **argv) {
    Solution s;
    vector<int> test_case_1{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    EXPECT_EQ(s.shipWithinDays(test_case_1, 5), 15);

    vector<int> test_case_2{3, 2, 2, 4, 1, 4};
    EXPECT_EQ(s.shipWithinDays(test_case_2, 3), 6);

    vector<int> test_case_3{1, 2, 3, 1, 1};
    EXPECT_EQ(s.shipWithinDays(test_case_3, 4), 3);
    return EXIT_SUCCESS;
}