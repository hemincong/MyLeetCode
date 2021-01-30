//
// Created by mincong.he on 2021/1/31.
//

#include "AlgoUtils.h"
#include <string>

using namespace std;

class Solution {
public:
    int numSimilarGroups(vector<string> &strs) {
        auto n = strs.size();
        if (n <= 1) return n;

        _parent = vector<int>(n, 0);
        for (int i = 0; i < n; ++i) {
            _parent[i] = i;
        }

        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (_similar_word(strs[i], strs[j])) {
                    _union(i, j);
                }
            }
        }

        int count = 0;
        for (int i = 0; i < n; ++i) {
            if (_parent[i] == i) count++;
        }

        return count;
    }

private:
    static bool _similar_word(const string &w1, const string &w2) {
        auto l_1 = w1.size();
        auto l_2 = w2.size();
        if (l_1 != l_2) return false;

        int pos = -1;
        int count = 0;
        for (int i = 0; i < l_1; ++i) {
            if (w1[i] != w2[i]) {
                count++;
                if (count > 2) return false;
                if (pos != -1 && (w1[pos] != w2[i] || w2[pos] != w1[i])) return false; // 比对是不是互换
                pos = i; // 第一次时，记录位置
            }
        }
        return true;
    }

    void _union(int p, int q) {
        auto p_root = _find(p);
        auto q_root = _find(q);

        if (p_root == q_root) return;

        _parent[p_root] = q_root;
    }

    int _find(int x) {
        if (_parent[x] == x) {
            return _parent[x];
        }

        _parent[x] = _find(_parent[x]);
        return _parent[x];
    }

    vector<int> _parent;
};

int main(int argc, char **argv) {
    Solution s;
    vector<string> test_case_1{"tars", "rats", "arts", "star"};
    EXPECT_EQ(s.numSimilarGroups(test_case_1), 2);

    vector<string> test_case_2{"omv", "ovm"};
    EXPECT_EQ(s.numSimilarGroups(test_case_2), 1);
    return EXIT_SUCCESS;
}