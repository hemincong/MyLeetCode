#include <vector>
#include "AlgoUtils.h"

using namespace std;

class Solution {
public:
    vector<int> platesBetweenCandles(string s, vector<vector<int>> &queries) {
        auto n = s.size();
        vector<int> right(n, -1);
        vector<int> left(n, -1);
        vector<int> candles_sum(n, 0);
        int candles = 0;
        for (int i = 0; i < n; ++i) {
            if (s[i] == '*') candles++;
            candles_sum[i] = candles;
        }

        int l = -1;
        for (int i = 0; i < n; ++i) {
            if (s[i] == '|') l = i;
            left[i] = l;
        }

        int r = -1;
        for (int i = n - 1; i >= 0; --i) {
            if (s[i] == '|') r = i;
            right[i] = r;
        }

        vector<int> ans;
        for (const auto &q: queries) {
            int l_bound = right[q[0]];
            int r_bound = left[q[1]];
            if (r_bound == -1 || l_bound == -1 || l_bound >= r_bound) {
                ans.push_back(0);
            } else {
                ans.push_back(candles_sum[r_bound] - candles_sum[l_bound]);
            }
        }
        return ans;
    }
};

int main(int argc, char **argv) {
    Solution s;
    auto s_1 = "**|**|***|";
    vector<vector<int>> queries_1{{2, 5},
                                  {5, 9}};
    vector<int> ret_1{2, 3};
    assertArray(s.platesBetweenCandles(s_1, queries_1), ret_1);

    auto s_2 = "***|**|*****|**||**|*";
    vector<vector<int>> queries_2{{1,  17},
                                  {4,  5},
                                  {14, 17},
                                  {5,  11},
                                  {15, 16}};
    vector<int> ret_2{9, 0, 0, 0, 0};
    assertArray(s.platesBetweenCandles(s_2, queries_2), ret_2);
    return EXIT_SUCCESS;
}