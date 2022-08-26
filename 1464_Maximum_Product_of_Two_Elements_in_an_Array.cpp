#include <vector>
#include "AlgoUtils.h"

using namespace std;

class Solution {
public:
    int maxProduct(vector<int> &nums) {
        int max_1 = INT_MIN;
        int max_2 = INT_MIN;
        for (auto n: nums) {
            if (n >= max_1) {
                max_2 = max_1;
                max_1 = n;
            } else if (n >= max_2) {
                max_2 = n;
            }
        }
        return (max_1 - 1) * (max_2 - 1);
    }
};
