//
// Created by mincong.he on 2021/1/1.
//

#include "AlgoUtils.h"

#include <vector>

using namespace std;

class Solution {
public:
    bool canPlaceFlowers(vector<int> &flowerbed, int n) {
        if (flowerbed.empty()) return false;
        if (n == 0) return true;

        flowerbed.insert(flowerbed.begin(), 0);
        flowerbed.push_back(0);

        int p = 1;
        int count = 0;

        while (p < flowerbed.size() - 1) {
            if (flowerbed[p - 1] == 0 &&
                flowerbed[p] == 0 &&
                flowerbed[p + 1] == 0) {
                count++;
                flowerbed[p] = 1;
                if (count >= n) return true;
            }
            p++;
        }
        return false;
    }
};

int main(int argc, char **argv) {
    Solution s;
    vector<int> test_case_1{1, 0, 0, 0, 1};
    vector<int> test_case_2{1, 0, 0, 0, 0, 1};
    vector<int> test_case_3{1, 0, 0, 0, 1, 0, 0};
    EXPECT_TRUE(s.canPlaceFlowers(test_case_1, 0));
    EXPECT_TRUE(s.canPlaceFlowers(test_case_1, 1));
    EXPECT_FALSE(s.canPlaceFlowers(test_case_1, 2));
    EXPECT_FALSE(s.canPlaceFlowers(test_case_2, 2));
    EXPECT_TRUE(s.canPlaceFlowers(test_case_3, 2));
    return EXIT_SUCCESS;
}
