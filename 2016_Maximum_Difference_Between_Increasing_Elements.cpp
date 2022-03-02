//
// Created by mincong.he on 2022/2/27.
//

#include <vector>
#include "AlgoUtils.h"

using namespace std;

class Solution {
public:
    int maximumDifference(vector<int> &nums) {
        int min = nums[0];
        int max_diff = -1;
        int n = nums.size();
        for (int i = 1; i < n; ++i) {
            auto diff = nums[i] - min;
            if (diff > max_diff && diff > 0) max_diff = diff;
            if (nums[i] < min) min = nums[i];
        }
        return max_diff;
    }
};

int main(int argc, char **argv) {
    Solution s;
    vector<int> test_case_1{7, 1, 5, 4};
    EXPECT_EQ(s.maximumDifference(test_case_1), 4)

    vector<int> test_case_2{9, 4, 3, 2};
    EXPECT_EQ(s.maximumDifference(test_case_2), -1)

    vector<int> test_case_3{1, 5, 2, 10};
    EXPECT_EQ(s.maximumDifference(test_case_3), 9)

    vector<int> test_case_4{999, 997, 980, 976, 948, 940, 938, 928, 924, 917, 907, 907, 881, 878, 864, 862, 859, 857,
                            848, 840, 824, 824, 824, 805, 802, 798, 788, 777, 775, 766, 755, 748, 735, 732, 727, 705,
                            700, 697, 693, 679, 676, 644, 634, 624, 599, 596, 588, 583, 562, 558, 553, 539, 537, 536,
                            509, 491, 485, 483, 454, 449, 438, 425, 403, 368, 345, 327, 287, 285, 270, 263, 255, 248,
                            235, 234, 224, 221, 201, 189, 187, 183, 179, 168, 155, 153, 150, 144, 107, 102, 102, 87, 80,
                            57, 55, 49, 48, 45, 26, 26, 23, 15};
    EXPECT_EQ(s.maximumDifference(test_case_4), -1)

    return EXIT_SUCCESS;
}