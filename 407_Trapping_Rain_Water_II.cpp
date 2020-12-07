//
// Created by mincong.he on 2020/12/7.
//

#include <vector>
#include "AlgoUtils.h"

using namespace std;

struct Qitem {
    int row;
    int col;
    int level;
};

static const int d_row[] = {-1, 1, 0, 0};
static const int d_col[] = {0, 0, -1, 1};

class Solution {
public:
    int trapRainWater(vector<vector<int>> &heightMap) {
        if (heightMap.size() < 3 || heightMap[0].size() < 3) return 0;
        auto qitem_cmp = [](const Qitem &lhs, const Qitem &rhs) {
            return lhs.level > rhs.level;
        };
        std::priority_queue<Qitem, std::vector<Qitem>, decltype(qitem_cmp)> q(qitem_cmp);
        auto row = heightMap.size();
        auto col = heightMap[0].size();
        auto check_record = vector<vector<int>>(row, vector<int>(col, 0));

        for (int r_i = 0; r_i < row; ++r_i) {
            check_record[r_i][0] = 1;
            check_record[r_i][col - 1] = 1;
            q.push(Qitem{r_i, 0, heightMap[r_i][0]});
            q.push(Qitem{r_i, (int) (col - 1), heightMap[r_i][col - 1]});
        }
        for (int c_i = 1; c_i < col - 1; ++c_i) {
            check_record[0][c_i] = 1;
            check_record[row - 1][c_i] = 1;
            q.push(Qitem{0, c_i, heightMap[0][c_i]});
            q.push(Qitem{(int) (row - 1), c_i, heightMap[row - 1][c_i]});
        }

        int total = 0;
        while (!q.empty()) {
            auto item = q.top();
            auto item_row = item.row;
            auto item_col = item.col;
            auto item_level = item.level;
            std::cout << "row:" << item_row << " col:" << item_col << std::endl;
            q.pop();
            for (int d = 0; d < 4; ++d) {
                auto new_row = item_row + d_row[d];
                auto new_col = item_col + d_col[d];

                if (new_row < 0 || new_col < 0 || new_row >= row || new_col >= col ||
                    check_record[new_row][new_col] > 0) {
                    continue;
                }

                auto new_level = heightMap[new_row][new_col];
                auto level_delta = item_level - new_level;
                if (level_delta > 0) {
                    total += level_delta;
                    std::cout << "level_delta: " << level_delta << " total:" << total << std::endl;
                    heightMap[new_row][new_col] = item_level;
                }

                std::cout << "push: row:" << new_row <<
                          " col:" << new_col <<
                          " level:" << heightMap[new_row][new_col]
                          << std::endl;
                auto new_item = Qitem{new_row, new_col, heightMap[new_row][new_col]};
                q.push(new_item);
                check_record[new_row][new_col] = 1;
            }
        }

        return total;
    }
};

int main(int argc, char **argv) {
    vector<vector<int>> test_case_1{{1, 4, 3, 1, 3, 2},
                                    {3, 2, 1, 3, 2, 4},
                                    {2, 3, 3, 2, 3, 1}};
    vector<vector<int>> test_case_2{{12, 13, 1,  12},
                                    {13, 4,  13, 12},
                                    {13, 8,  10, 12},
                                    {12, 13, 12, 12},
                                    {13, 13, 13, 13},
    };
    Solution solution;
    auto ret = solution.trapRainWater(test_case_1);
    EXPECT_EQ(ret, 4);

    auto ret_2 = solution.trapRainWater(test_case_2);
    EXPECT_EQ(ret_2, 14);

    return EXIT_SUCCESS;
}