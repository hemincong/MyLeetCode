#include <vector>
#include "AlgoUtils.h"

using namespace std;

class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>> &mat, int k) {
        vector<pair<int, int>> v;
        auto n = mat.size();
        for (int i = 0; i < n; ++i) {
            auto count = 0;
            for (const auto &c : mat[i]) {
                if (c == 1) {
                    count++;
                }
            }
            v.emplace_back(make_pair(count, i));
        }
        sort(v.begin(), v.end(), [](const auto &p1, const auto &p2) {
            if (p1.first == p2.first) return p1.second < p2.second;
            return p1.first < p2.first;
        });
        vector<int> ret;
        for (auto &[count, index]: v) {
            if (k == 0) break;
            ret.emplace_back(index);
            k--;
        }
        return ret;
    }
};

int main(int argc, char **argv) {
    Solution s;
    vector<vector<int>> mat_1 = {{1, 1, 0, 0, 0},
                                 {1, 1, 1, 1, 0},
                                 {1, 0, 0, 0, 0},
                                 {1, 1, 0, 0, 0},
                                 {1, 1, 1, 1, 1}};
    vector<int> ret_1{2, 0, 3};
    assertArray(s.kWeakestRows(mat_1, 3), ret_1);
    vector<vector<int>> mat_2 = {{1, 0, 0, 0},
                                 {1, 1, 1, 1},
                                 {1, 0, 0, 0},
                                 {1, 0, 0, 0}};
    vector<int> ret_2{0, 2};
    assertArray(s.kWeakestRows(mat_2, 2), ret_2);
    vector<vector<int>> mat_3 = {{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0},
                                 {1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                                 {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
                                 {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                                 {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0},
                                 {1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                                 {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0},
                                 {1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                                 {1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                                 {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0},
                                 {1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                                 {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0},
                                 {1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                                 {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0},
                                 {1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0},
                                 {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
                                 {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0},
                                 {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                                 {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0},
                                 {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0},
                                 {1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0},
                                 {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                                 {1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                                 {1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                                 {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0},
                                 {1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                                 {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0},
                                 {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0}};
    vector<int> ret_3{17, 21, 3, 7, 12, 25, 1};
    assertArray(s.kWeakestRows(mat_3, 7), ret_3);

    return EXIT_SUCCESS;
}