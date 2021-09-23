#include <vector>
#include "AlgoUtils.h"

using namespace std;

class Solution {
public:
    bool isPowerOfThree(int n) {
        const vector<int> nums{1, 3, 9, 27, 81, 243, 729, 2187, 6561, 19683, 59049, 177147, 531441, 1594323, 4782969,
                               14348907, 43046721, 129140163, 387420489, 1162261467};
        int l = 0;
        int r = nums.size() - 1;
        while (l < r) {
            int mid = l + ((r - l) >> 1);
            if (nums[mid] == n) {
                return true;
            } else if (nums[mid] < n) {
                l = mid + 1;
            } else {
                r = mid;
            }
        }
        return nums[l] == n;
    }
};

class Solution {
public:
    bool isPowerOfThree(int n) {
        switch (n) {
            case 1:
            case 3:
            case 9:
            case 27:
            case 81:
            case 243:
            case 729:
            case 2187:
            case 6561:
            case 19683:
            case 59049:
            case 177147:
            case 531441:
            case 1594323:
            case 4782969:
            case 14348907:
            case 43046721:
            case 129140163:
            case 387420489:
            case 1162261467:
                return true;
            default:
                return false;
        }
    }
};

int main(int argc, char **argv) {
    Solution s;
    return EXIT_SUCCESS;
}