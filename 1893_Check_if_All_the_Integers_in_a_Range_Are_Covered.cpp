#include <vector>
#include "AlgoUtils.h"

using namespace std;

class Solution {
public:
    bool isCovered(vector<vector<int>> &ranges, int left, int right) {
        vector<int> bits(right - left + 1, 0);
        for (auto &r : ranges) {
            for (int i = r[0]; i <= r[1]; ++i) {
                if (i >= left && i <= right) {
                    bits[i - left] = 1;
                }
            }
        }
        return all_of(bits.begin(), bits.end(), [&](auto &n) {
            return n == 1;
        });
    }
};

int main(int argc, char **argv) {
    Solution s;
    vector<vector<int>> test_case_1{{1, 2},
                                    {3, 4},
                                    {5, 6}};
    vector<vector<int>> test_case_2{{1,  10},
                                    {10, 20}};
    EXPECT_TRUE(s.isCovered(test_case_1, 2, 5));
    EXPECT_FALSE(s.isCovered(test_case_2, 21, 21));
    return EXIT_SUCCESS;
}