//
// Created by mincong.he on 2020/6/5.
//

#include <vector>

using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>> &matrix) {
        vector<int> ret;
        if (matrix.empty()) return ret;

        int n = matrix.size();
        int m = matrix[0].size();

        int curr_n_limit = 0;
        int curr_m_limit = 0;

        int x;
        int y;
        while (true) {
            x = curr_n_limit;
            if (x >= n - curr_n_limit) break;
            for (auto i = curr_m_limit; i < m - curr_m_limit; i++) {
                ret.push_back(matrix[x][i]);
            }

            y = m - curr_m_limit - 1;
            if (y < curr_m_limit) break;
            for (auto i = curr_n_limit + 1; i < n - curr_n_limit; i++) {
                ret.push_back(matrix[i][y]);
            }

            x = n - curr_n_limit - 1;
            if (x <= curr_n_limit) break;
            curr_m_limit++;
            for (auto i = m - curr_m_limit - 1; i > curr_m_limit - 1; i--) {
                ret.push_back(matrix[x][i]);
            }

            y = curr_m_limit - 1;
            if (y > m - curr_m_limit - 1) break;
            for (auto i = n - curr_n_limit - 1; i > curr_n_limit; i--) {
                ret.push_back(matrix[i][y]);
            }
            curr_n_limit++;
        }
        return ret;
    }
};

int main(int argc, char **argv) {
    vector<vector<int>> test_case1{
            {1,  2,  3,  4},
            {10, 11, 12, 5},
            {9,  8,  7,  6}
    };
    vector<vector<int>> test_case2{
            {1, 2, 3},
            {8, 9, 4},
            {7, 6, 5}
    };
    vector<vector<int>> test_case3{
            {1,  2,  3},
            {10, 11, 4},
            {9,  12, 5},
            {8,  7,  6}
    };
    vector<vector<int>> test_case4{
            {1},
            {2},
            {3},
            {4}
    };
    vector<vector<int>> test_case5{
            {1, 2, 3, 4},
    };
    vector<vector<int>> test_case6{
            {1},
    };
    vector<vector<int>> test_case7{
    };
    vector<vector<int>> test_case8{
            {1, 2, 3},
            {6, 5, 4},
    };
    vector<vector<int>> test_case9{
            {1, 2},
            {6, 3},
            {5, 4},
    };
    Solution solution;
    vector<vector<vector<int>>> test_cases;
    test_cases.emplace_back(test_case1);
    test_cases.emplace_back(test_case2);
    test_cases.emplace_back(test_case3);
    test_cases.emplace_back(test_case4);
    test_cases.emplace_back(test_case5);
    test_cases.emplace_back(test_case6);
    test_cases.emplace_back(test_case7);
    test_cases.emplace_back(test_case8);
    test_cases.emplace_back(test_case9);
    for (auto &t: test_cases) {
        auto ret = solution.spiralOrder(t);
        for (const auto &c: ret) {
            printf("%d ", c);
        }
        printf("\n");
    }
    return EXIT_SUCCESS;
}