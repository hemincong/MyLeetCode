#include <vector>
#include "AlgoUtils.h"

using namespace std;

class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>> &img) {
        int m = img.size();
        int n = img[0].size();
        vector<vector<int>> ret(m, vector<int>(n, 0));

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                int base = 0;
                long long v = 0;
                for (const auto &d: _dir) {
                    int new_x = i + d.first;
                    int new_y = j + d.second;
                    if (new_x < 0 || new_y < 0 || new_x >= m || new_y >= n) continue;
                    base++;
                    v += img[new_x][new_y];
                }
                ret[i][j] = v / base;
            }

        }
        return ret;
    }

private:
    const vector<pair<int, int>> _dir{
            {-1, 1},
            {0,  1},
            {1,  1},
            {-1, 0},
            {0,  0},
            {1,  0},
            {-1, -1},
            {0,  -1},
            {1,  -1}
    };
};

int main(int argc, char **argv) {
    Solution s;
    return EXIT_SUCCESS;
}