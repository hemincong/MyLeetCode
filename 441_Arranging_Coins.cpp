#include <vector>
#include "AlgoUtils.h"

using namespace std;

class Solution {
public:
    int arrangeCoins(int n) {
        int k = 0;
        while (n - k > 0) {
            k++;
            n -= k;
        }
        return k;
    }
};

int main(int argc, char **argv) {
    Solution s;
    return EXIT_SUCCESS;
}