#include <vector>
#include <numeric>
#include "AlgoUtils.h"

using namespace std;

class Solution {
public:
    vector<int> missingRolls(vector<int> &rolls, int mean, int n) {
        long total = accumulate(rolls.begin(), rolls.end(), 0);
        auto count = rolls.size();
        vector<int> ret;
        long remind = ((n + count) * mean) - total;
        if (remind < n || (remind == 0 && n != 0) || remind > n * 6 ) return ret;

        ret.resize(n);
        for (int i = n; i > 0; i--) {
            int to_m = remind / i;
            ret[i - 1] = to_m;
            remind -= to_m;
        }

        return ret;
    }
};

int main(int argc, char **argv) {
    Solution s;
    vector<int> rolls_5{4, 2, 2, 5, 4, 5, 4, 5, 3, 3, 6, 1, 2, 4, 2, 1, 6, 5, 4, 2, 3, 4, 2, 3, 3, 5, 4, 1, 4, 4, 5, 3,
                        6, 1, 5, 2, 3, 3, 6, 1, 6, 4, 1, 3};
    vector<int> ret_5{};
    assertArray(s.missingRolls(rolls_5, 2, 53), ret_5);

    vector<int> rolls_4{6, 3, 4, 5, 5, 3};
    vector<int> ret_4{};
    assertArray(s.missingRolls(rolls_4, 1, 6), ret_4);

    vector<int> rolls_1{3, 2, 4, 3};
    vector<int> ret_1{6, 6};
    assertArray(s.missingRolls(rolls_1, 4, 2), ret_1);

    vector<int> rolls_2{1, 5, 6};
    vector<int> ret_2{2, 3, 2, 2};
    assertArray(s.missingRolls(rolls_2, 3, 4), ret_2);

    vector<int> rolls_3{1, 2, 3, 4};
    vector<int> ret_3{};
    assertArray(s.missingRolls(rolls_3, 6, 4), ret_3);
    return EXIT_SUCCESS;
}