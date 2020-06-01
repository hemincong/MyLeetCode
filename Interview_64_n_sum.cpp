//
// Created by mincong.he on 2020/6/2.
//

#include <cassert>

class Solution {
public:
    int sumNums(int n) {
        n && (n += sumNums(n - 1));
        return n;
    }
};

int main(int argc, char **argv) {
    Solution solution;
    assert(solution.sumNums(3) == 6);
    assert(solution.sumNums(9) == 45);
}