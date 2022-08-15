#include <vector>
#include "AlgoUtils.h"

using namespace std;

class Solution {
public:
    vector<vector<int>> outerTrees(vector<vector<int>> &trees) {
        int n = trees.size();
        if (n < 4) {
            return trees;
        }
        int leftMost = 0;
        for (int i = 0; i < n; i++) {
            if (trees[i][0] < trees[leftMost][0]) {
                leftMost = i;
            }
        }

        vector<vector<int>> res;
        vector<bool> visit(n, false);
        int p = leftMost;
        do {
            int q = (p + 1) % n;
            for (int r = 0; r < n; r++) {
                /* 如果 r 在 pq 的右侧，则 q = r */
                if (cross(trees[p], trees[q], trees[r]) < 0) {
                    q = r;
                }
            }
            /* 是否存在点 i, 使得 p 、q 、i 在同一条直线上 */
            for (int i = 0; i < n; i++) {
                if (visit[i] || i == p || i == q) {
                    continue;
                }
                if (cross(trees[p], trees[q], trees[i]) == 0) {
                    res.emplace_back(trees[i]);
                    visit[i] = true;
                }
            }
            if (!visit[q]) {
                res.emplace_back(trees[q]);
                visit[q] = true;
            }
            p = q;
        } while (p != leftMost);
        return res;
    }

private:
    static int cross(const vector<int> &p, const vector<int> &q, const vector<int> &r) {
        return (((q[0] - p[0]) * (r[1] - q[1])) -
                ((q[1] - p[1]) * (r[0] - q[0])));
    }
};

int main(int argc, char **argv) {
    Solution s;
    vector<vector<int>> trees_1{{1, 1},
                                {2, 2},
                                {2, 0},
                                {2, 4},
                                {3, 3},
                                {4, 2}};
    printMatrix(s.outerTrees(trees_1)); // [[1,1],[2,0],[3,3],[2,4],[4,2]]

    vector<vector<int>> trees_2{{1, 2},
                                {2, 2},
                                {4, 2}};
    printMatrix(s.outerTrees(trees_2)); // [[4,2],[2,2],[1,2]]

    return EXIT_SUCCESS;
}