//
// Created by mincong.he on 2021/7/2.
//

#include <vector>
#include "AlgoUtils.h"

using namespace std;

class Solution {
public:
    bool exist(vector<vector<char>> &board, string word) {
        _m = board.size();
        if (_m == 0) return false;
        _n = board[0].size();
        if (_n == 0) return false;
        _len = word.size();
        _word = word;
        _board = board;

        for (int i = 0; i < _m; ++i) {
            for (int j = 0; j < _n; ++j) {
                auto ret = dfs(0, i, j);
                if (ret) return true;
            }
        }
        return false;
    }

private:
    bool dfs(int word_pos,
             int x, int y) {
        if (_board[x][y] != _word[word_pos]) return false;
        if (word_pos == _len - 1) return true;

        // std::cout << "x: " << x << " y: " << y << " pos: " << word_pos << std::endl;

        // true, continue
        auto temp = _board[x][y];
        _board[x][y] = '#';

        for (int i = 0; i < 4; i++) {
            auto new_x = x + _delta[i * 2];
            auto new_y = y + _delta[i * 2 + 1];
            if (new_x >= 0 && new_x < _m && new_y >= 0 && new_y < _n) {
                auto ret = dfs(word_pos + 1, new_x, new_y);
                if (ret) return true;
            }
        }
        _board[x][y] = temp;
        return false;
    }

    int _delta[8] = {0, 1,
                     1, 0,
                     0, -1,
                     -1, 0};

    int _m;
    int _n;
    int _len;
    string _word;
    vector<vector<char>> _board;
};

int main(int argc, char **argv) {
    Solution s;
    vector<vector<char>> test_case_1{{'A', 'B', 'C', 'E'},
                                     {'S', 'F', 'C', 'S'},
                                     {'A', 'D', 'E', 'E'}};
    EXPECT_TRUE(s.exist(test_case_1, "ABCCED"));
    EXPECT_TRUE(s.exist(test_case_1, "SEE"));
    EXPECT_FALSE(s.exist(test_case_1, "ABCB"));
    vector<vector<char>> test_case_2{{'a'}};
    EXPECT_TRUE(s.exist(test_case_2, "a"));
    vector<vector<char>> test_case_3{{'A', 'A', 'A', 'A', 'A', 'A'},
                                     {'A', 'A', 'A', 'A', 'A', 'A'},
                                     {'A', 'A', 'A', 'A', 'A', 'A'},
                                     {'A', 'A', 'A', 'A', 'A', 'A'},
                                     {'A', 'A', 'A', 'A', 'A', 'A'},
                                     {'A', 'A', 'A', 'A', 'A', 'A'}};
    EXPECT_FALSE(s.exist(test_case_3, "AAAAAAAAAAAAAAB"));
    return EXIT_SUCCESS;

}