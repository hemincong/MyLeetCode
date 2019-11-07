//
// Created by mincong.he on 2019/11/4.
//

#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        std::vector<std::vector<std::string>> result;
        std::vector<std::vector<int>> mark;
        std::vector<std::string> location;

        for (int i = 0; i < n; i++) {
            mark.emplace_back(std::vector<int>(n, 0));
            location.emplace_back("");
            location[i].append(n, '.');
        }

        generate(0, n, location, result, mark);
        return result;
    }

private:
    static void put_down_the_queen(int x, int y, std::vector<std::vector<int>> &mark) {
        static const int dx[] = {-1, 1, 0, 0, -1, -1, 1, 1};
        static const int dy[] = {0, 0, -1, 1, -1, 1, -1, 1};
        mark[x][y] = 1;
        // 延伸到棋盘长度，里面判断是不是范围内
        for (int i = 1; i < mark.size(); i++) {
            // 8个方向
            for (int j = 0; j < 8; j++) {
                int new_x = x + dx[j] * i;
                int new_y = y + dy[j] * i;
                if (new_x >= 0 && new_x < mark.size() &&
                    new_y >= 0 && new_y < mark.size()) {
                    mark[new_x][new_y] = 1;
                }
            }
        }
    }

    static void generate(int k, int n,
                  std::vector<std::string> &location, // 当前棋盘,皇后的位置
                  std::vector<std::vector<std::string>> &result, // 可能的方案
                  std::vector<std::vector<int>> &mark) { // 记录不能下的地方
        if (k == n) {
            result.push_back(location);
            return;
        }

        // 因为每一列只能一个，就直接列为k
        // 行
        for (int i = 0; i < n; i++) {
            // 0就是没下过
            if (mark[k][i] == 0) {
                // 记下旧的
                std::vector<std::vector<int>> tmp_vec = mark;
                location[k][i] = 'Q';
                // 记录不能下的位置
                put_down_the_queen(k, i, mark);
                // 分支1：下一步, K+1
                generate(k + 1, n, location, result, mark);
                // 分支2：这一列的下一空格, 恢复这个循环内的场景
                mark = tmp_vec;
                location[k][i] = '.';
            }
        }
    }
};

int main(int argc, char **argv) {
    Solution solution;
    auto result = solution.solveNQueens(4);
    for (const auto &l : result) {
        for (const auto &c : l) {
            std::cout << c << std::endl;
        }
        std::cout << std::endl;
    }
    return EXIT_SUCCESS;
}