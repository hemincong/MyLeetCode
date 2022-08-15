#include <vector>
#include "AlgoUtils.h"

using namespace std;

class Solution {
public:
    vector<int> numberOfLines(vector<int> &widths, string s) {
        int ret = 1;
        int count = 0;
        for (const auto &c: s) {
            count += widths[c - 'a'];
            if (count > 100) {
                ret++;
                count = widths[c - 'a'];
            }
        }
        return {ret, count};
    }
};

int main(int argc, char **argv) {
    Solution s;
    return EXIT_SUCCESS;
}