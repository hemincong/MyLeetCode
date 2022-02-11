#include <vector>
#include "AlgoUtils.h"

using namespace std;

class Solution {
public:
    int minOperations(vector<int> &target, vector<int> &arr) {

    }
};

int main(int argc, char **argv) {
    Solution s;
    vector<int> target_1{5, 1, 3};
    vector<int> arr_1{9, 4, 2, 3, 4};
    vector<int> target_2{6, 4, 8, 1, 3, 2};
    vector<int> arr_2{4, 7, 6, 2, 3, 8, 6, 1};
    EXPECT_EQ(s.minOperations(target_1, arr_1), 2);
    EXPECT_EQ(s.minOperations(target_2, arr_2), 3);

    return EXIT_SUCCESS;
}