#include <vector>
#include "AlgoUtils.h"

using namespace std;

class Solution {
public:
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> ret;
        for (int i = left; i <= right; ++i) {
            auto t = i;
            bool flag = true;
            while (t > 0) {
                auto p = t % 10;
                if (p == 0 || i % p != 0) {
                    flag = false;
                    break;
                }
                t = t / 10;
            }
            if (flag) ret.push_back(i);
        }
        return ret;
    }
};

int main(int argc, char **argv) {
    Solution s;
    return EXIT_SUCCESS;
}