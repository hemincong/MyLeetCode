//
// Created by mincong.he on 2021/2/12.
//

#include "AlgoUtils.h"
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        auto ret = vector<int>(rowIndex + 1, 1);
        for (int i = 0; i <= rowIndex; ++i) {
            for (int j = i; j > 0; --j) {
                if (j == 0 || j == i) {
                    ret[j] = 1;
                } else {
                    ret[j] += ret[j - 1];
                }
            }
        }
        return ret;
    }
};

int main(int argc, char **argv) {
    Solution s;
    std::vector<int> ret_3{1, 3, 3, 1};
    assertArray(s.getRow(3), ret_3);

    return EXIT_SUCCESS;
}