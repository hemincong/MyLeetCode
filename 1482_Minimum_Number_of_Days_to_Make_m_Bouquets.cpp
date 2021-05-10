//
// Created by mincong.he on 2021/5/9.
//

#include <vector>

#include "AlgoUtils.h"

using namespace std;

class Solution {
public:
    int minDays(vector<int> &bloomDay, int m, int k) {
        int low = INT_MAX;
        int high = 0;
        int n = bloomDay.size();
        if (m > n / k) return -1;
        for (const auto &b : bloomDay) {
            if (b < low) low = b;
            if (b > high) high = b;
        }
        while (low < high) {
            int half = low + ((high - low) / 2);
            auto check_ret = _check(bloomDay, m, k, half);
            if (check_ret) {
                high = half;
            } else {
                low = half + 1;
            }
        }
        return low;
    }

private:
    bool _check(const vector<int> &bloomDay, int m, int k, int d) {
        int k_count = 0;
        int m_count = 0;
        for (int i : bloomDay) {
            if (i <= d) {
                k_count++;
                if (k_count == k) {
                    k_count = 0;
                    m_count++;
                }
            } else {
                k_count = 0;
            }
            if (m_count >= m) return true;
        }
        return false;
    }
};

int main(int argc, char **argv) {
    Solution s;
    vector<int> bloomDay_1{1, 10, 3, 10, 2};
    EXPECT_EQ(s.minDays(bloomDay_1, 3, 1), 3)

    vector<int> bloomDay_2{1, 10, 3, 10, 2};
    EXPECT_EQ(s.minDays(bloomDay_2, 3, 2), -1)

    vector<int> bloomDay_3{7, 7, 7, 7, 12, 7, 7};
    EXPECT_EQ(s.minDays(bloomDay_3, 2, 3), 12)

    vector<int> bloomDay_4{1000000000, 1000000000};
    EXPECT_EQ(s.minDays(bloomDay_4, 1, 1), 1000000000)

    vector<int> bloomDay_5{1, 10, 2, 9, 3, 8, 4, 7, 5, 6};
    EXPECT_EQ(s.minDays(bloomDay_5, 4, 2), 9)
    return EXIT_SUCCESS;
}