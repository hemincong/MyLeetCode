#include <vector>
#include "AlgoUtils.h"
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> restoreArray(vector<vector<int>> &adjacentPairs) {
        unordered_map<int, vector<int>> m;
        for (auto &p : adjacentPairs) {
            m[p[0]].push_back(p[1]);
            m[p[1]].push_back(p[0]);
        }
        auto n = adjacentPairs.size() + 1;
        vector<int> ret(n, 0);
        for (const auto &i : m) {
            if (i.second.size() == 1) {
                ret[0] = i.first;
                break;
            }
        }
        ret[1] = m[ret[0]][0];
        for (int i = 2; i < n; ++i) {
            // 防止回头
            if (m[ret[i - 1]][0] == ret[i - 2]) {
                ret[i] = m[ret[i - 1]][1];
            } else {
                ret[i] = m[ret[i - 1]][0];
            }
        }
        return ret;
    }
};

int main(int argc, char **argv) {
    Solution s;
    vector<vector<int>> test_case_1{{2, 1},
                                    {3, 4},
                                    {3, 2}};
    vector<int> ret_1{1, 2, 3, 4};
    assertArray(s.restoreArray(test_case_1), ret_1);

    vector<vector<int>> test_case_2{{4,  -2},
                                    {1,  4},
                                    {-3, 1}};
    vector<int> ret_2{-2, 4, 1, -3};
    assertArray(s.restoreArray(test_case_2), ret_2);

    vector<vector<int>> test_case_3{{100000, -100000}};
    vector<int> ret_3{100000, -100000};
    assertArray(s.restoreArray(test_case_3), ret_3);

    return EXIT_SUCCESS;
}