//
// Created by mincong.he on 2022/2/28.
//

#include <vector>
#include <map>
#include <set>
#include "AlgoUtils.h"

using namespace std;

class Solution {
public:
    int maximumRequests(int n, vector<vector<int>> &requests) {
        ans = 0;
        delta.resize(n);
        zero = n;
        _n = n;
        dfs(requests, 0);
        return ans;
    }

private:
    void dfs(vector<vector<int>> &requests, int pos) {
        if (pos == requests.size()) {
            if (zero == _n) {
                ans = max(ans, cnt);
            }
            return;
        }
        dfs(requests, pos + 1);
        int z = zero;
        ++cnt;
        auto &r = requests[pos];
        int x = r[0];
        int y = r[1];
        --delta[x];
        zero += delta[x] == 0;
        zero -= delta[y] == 0;
        ++delta[y];

        zero += delta[y] == 0;
        dfs(requests, pos + 1);
        --delta[y];
        ++delta[x];
        --cnt;
        zero = z;
    }

    vector<int> delta;
    int ans = 0;
    int cnt = 0;
    int zero;
    int _n;
};

int main(int argc, char **argv) {
    Solution s;
    vector<vector<int>> request_1{{0, 1},
                                  {1, 0},
                                  {0, 1},
                                  {1, 2},
                                  {2, 0},
                                  {3, 4}};
    EXPECT_EQ(s.maximumRequests(5, request_1), 5);

    vector<vector<int>> request_2{{0, 0},
                                  {1, 2},
                                  {2, 1}};
    EXPECT_EQ(s.maximumRequests(3, request_2), 3);

    vector<vector<int>> request_3{{0, 3},
                                  {3, 1},
                                  {1, 2},
                                  {2, 0}};
    EXPECT_EQ(s.maximumRequests(4, request_3), 4);

    return EXIT_SUCCESS;
}