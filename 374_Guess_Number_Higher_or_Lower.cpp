#include <vector>
#include "AlgoUtils.h"

using namespace std;

/**
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is lower than the guess number
 *			      1 if num is higher than the guess number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        int left = 0;
        int right = n;
        while (left <= right) {
            auto mid = left + ((right - left) >> 1);
            auto guess_ret = guess(mid);
            if (guess_ret == -1) {
                right = mid - 1;
            } else if (guess_ret == 1) {
                left = mid + 1;
            } else return mid;
        }
        return 0;
    }
};

int main(int argc, char **argv) {
    Solution s;
    return EXIT_SUCCESS;
}