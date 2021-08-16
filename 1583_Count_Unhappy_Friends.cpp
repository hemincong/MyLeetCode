#include <vector>
#include "AlgoUtils.h"

using namespace std;

class Solution {
public:
    int unhappyFriends(int n, vector<vector<int>> &preferences, vector<vector<int>> &pairs) {
        vector<vector<int>> order(n, vector<int>(n, 0));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n - 1; ++j) {
                order[i][preferences[i][j]] = j;
            }
        }

        vector<int> match(n, 0);
        for (auto &pair: pairs) {
            match[pair[0]] = pair[1];
            match[pair[1]] = pair[0];
        }

        int ret = 0;
        for (int x = 0; x < n; x++) {
            int y = match[x];
            int index = order[x][y];
            for (int i = 0; i < index; i++) {
                int u = preferences[x][i];
                int v = match[u];
                if (order[u][x] < order[u][v]) {
                    ret++;
                    break;
                }
            }
        }
        return ret;

    }
};

int main(int argc, char **argv) {
    Solution s;
    vector<vector<int>> preferences_1{{1, 2, 3},
                                      {3, 2, 0},
                                      {3, 1, 0},
                                      {1, 2, 0}};
    vector<vector<int>> pairs_1{{0, 1},
                                {2, 3}};
    EXPECT_EQ(s.unhappyFriends(4, preferences_1, pairs_1), 2);

    vector<vector<int>> preferences_2{{1},
                                      {0}};
    vector<vector<int>> pairs_2{{1, 0}};
    EXPECT_EQ(s.unhappyFriends(2, preferences_2, pairs_2), 0);

    vector<vector<int>> preferences_3{{1, 3, 2},
                                      {2, 3, 0},
                                      {1, 3, 0},
                                      {0, 2, 1}};
    vector<vector<int>> pairs_3{{1, 3},
                                {0, 2}};
    EXPECT_EQ(s.unhappyFriends(4, preferences_3, pairs_3), 4);
    return EXIT_SUCCESS;
}