#include <vector>
#include "AlgoUtils.h"

using namespace std;

class Solution {
public:
    int maxArea(vector<int> &height) {
        auto n = height.size();
        int i = 0;
        int j = n - 1;
        int max_area = INT_MIN;
        while (i < j) {
            max_area = max(min(height[j], height[i]) * (j - i), max_area);
            if (height[j] > height[i]) {
                i++;
            } else {
                j--;
            }
        }
        return max_area;
    }
};

int main(int argc, char **argv) {
    Solution s;

    vector<int> test_case_1{1, 8, 6, 2, 5, 4, 8, 3, 7};
    EXPECT_EQ(s.maxArea(test_case_1), 49);

    vector<int> test_case_2{1, 1};
    EXPECT_EQ(s.maxArea(test_case_2), 1);
    return EXIT_SUCCESS;
}