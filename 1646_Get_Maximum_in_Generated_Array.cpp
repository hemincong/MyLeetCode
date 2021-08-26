#include <vector>
#include "AlgoUtils.h"

using namespace std;

class Solution {
public:
    int getMaximumGenerated(int n) {
        if (n == 0) return 0;
        if (n == 1 || n == 2) return 1;
        vector<int> gen(n + 1);
        gen[0] = 0;
        gen[1] = 1;
        for (int i = 1; i <= n; ++i) {
            int two_times = i << 1;
            if (two_times >= 2 && two_times <= n) gen[two_times] = gen[i];
            if (two_times + 1 >= 2 && two_times + 1 <= n) gen[two_times + 1] = gen[i] + gen[i + 1];
        }
        return *max_element(gen.begin(), gen.end());
    }
};

int main(int argc, char **argv) {
    Solution s;
    EXPECT_EQ(s.getMaximumGenerated(7), 3);
    EXPECT_EQ(s.getMaximumGenerated(2), 1);
    return EXIT_SUCCESS;
}