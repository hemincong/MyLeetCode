//
// Created by mincong.he on 2022/2/21.
//
#include "AlgoUtils.h"
#include <string>

using namespace std;

class Solution {
public:
    string pushDominoes(string dominoes) {
        int n = dominoes.size();
        vector<char> s_vec(&dominoes.at(0), &dominoes.at(0) + n);
        for (int i = 0; i < n; ++i) {
            if (dominoes[i] != '.') continue;
            // 留着开始位
            int j = i + 1;
            while (j < n && dominoes[j] == '.') {
                j++;
            }
            replace(s_vec, i - 1, j);
            i = j;
        }
        s_vec.push_back('\0');
        return {&s_vec.at(0)};
    }

    static void replace(std::vector<char> &s_vec, int start, int end) {
        auto n = s_vec.size();
        // R..L
        if ((start >= 0 && s_vec[start] == 'R') && (end < n && s_vec[end] == 'L')) {
            while (start < end) {
                s_vec[start++] = 'R';
                s_vec[end--] = 'L';
            }
            // R..R or R..
        } else if ((start >= 0 && s_vec[start] == 'R') && (end == n || s_vec[end] == 'R')) {
            for (int i = start; i < end; ++i) {
                s_vec[i] = 'R';
            }
        }
        // L..L or ..L
        if (start <= 0) start = 0;
        if ((start == 0 || s_vec[start] == 'L') && (end < n && s_vec[end] == 'L')) {
            for (int i = start; i < end; ++i) {
                s_vec[i] = 'L';
            }
        }
        // L..R 不处理
    }
};

int main(int argc, char **argv) {
    Solution s;
    EXPECT_EQ(s.pushDominoes("RR.L"), "RR.L")
    EXPECT_EQ(s.pushDominoes(".L.R...LR..L.."), "LL.RR.LLRRLL..")
    EXPECT_EQ(s.pushDominoes(".L.R...LR..R.."), "LL.RR.LLRRRRRR")
    EXPECT_EQ(s.pushDominoes("R.."), "RRR")
    EXPECT_EQ(s.pushDominoes("R.......L.R........."), "RRRR.LLLL.RRRRRRRRRR")
    return EXIT_SUCCESS;
}