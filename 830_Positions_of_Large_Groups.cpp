//
// Created by mincong.he on 2021/1/5.
//

#include "AlgoUtils.h"

#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<vector<int>> largeGroupPositions(string s) {
        int len = s.size();
        vector<vector<int>> ret;
        if (len == 0) return ret;

        int p1 = 0;
        while (p1 < len) {
            int p2 = p1 + 1;
            while (p2 < len && s[p2] == s[p1]) {
                p2++;
            }
            if (p2 - p1 > 2) {
                ret.emplace_back(vector<int>{p1, p2 - 1});
            }
            p1 = p2;
        }
        return ret;
    }
};

int main(int argc, char **argv) {
    Solution s;
    printMatrix(s.largeGroupPositions("abbxxxxzzy"));
    printMatrix(s.largeGroupPositions("abc"));
    printMatrix(s.largeGroupPositions("abcdddeeeeaabbbcd"));
    return EXIT_SUCCESS;
}