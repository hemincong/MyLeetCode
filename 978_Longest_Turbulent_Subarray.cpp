#include <vector>
#include "AlgoUtils.h"

using namespace std;

class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        auto n = arr.size();
        if (n <= 1) return 1;

        int dp_down = 1;
        int dp_up = 1;
        int ret = 1;
        for (int i = 1; i < n; i++) {
            if (arr[i - 1] > arr[i]) {
                dp_down = dp_up + 1;
                dp_up = 1;
            } else if (arr[i - 1] < arr[i]) {
                dp_up = dp_down + 1;
                dp_down = 1;
            } else {
                dp_up = 1;
                dp_down = 1;
            }

            ret = dp_down > ret ? dp_down : ret;
            ret = dp_up > ret ? dp_up : ret;
        }
        return ret;
    }
};

int main(int argc, char** argv) {
    Solution s;
    vector<int> test_case_1{9,4,2,10,7,8,8,1,9};
    EXPECT_EQ(s.maxTurbulenceSize(test_case_1), 5)

    vector<int> test_case_2{4, 8, 12, 16};
    EXPECT_EQ(s.maxTurbulenceSize(test_case_2), 2);

    vector<int> test_case_3{100};
    EXPECT_EQ(s.maxTurbulenceSize(test_case_3), 1);

    vector<int> test_case_4{37,199,60,296,257,248,115,31,273,176};
    EXPECT_EQ(s.maxTurbulenceSize(test_case_4), 5);

    return EXIT_SUCCESS;
}