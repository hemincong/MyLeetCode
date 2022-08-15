//
// Created by mincong.he on 2022/4/18.
//

#include <vector>
#include "AlgoUtils.h"

using namespace std;

class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> ret;
        for (int i = 1; i <= 9; ++i) {
            dfs(ret, i, n);
        }
        return ret;
    }

    void dfs(vector<int>& v, int num, int n) {
        if (num > n) return;
        v.push_back(num);

        for (int i = 0; i <= 9; ++i) {
            auto k = num * 10 + i;
            dfs(v, k, n);
        }
    }
};

int main(int argc, char **argv) {
    Solution s;
    vector<int> ret_1{1, 10, 11, 12, 13, 14, 2, 3, 4, 5, 6, 7, 8, 9};
    assertArray(s.lexicalOrder(14), ret_1);

    vector<int> ret_2{1, 2};
    assertArray(s.lexicalOrder(2), ret_2);

    vector<int> ret_3{1, 10, 11, 12, 13, 2, 3, 4, 5, 6, 7, 8, 9};
    assertArray(s.lexicalOrder(13), ret_3);

    return EXIT_SUCCESS;
}