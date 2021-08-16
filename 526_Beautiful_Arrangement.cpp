#include <vector>
#include "AlgoUtils.h"

using namespace std;

class Solution {
public:
    int countArrangement(int n) {
        vector<int> visited(n + 1, 0);
        int count = 0;
        dfs(n, 1, count, visited);
        return count;
    }

    void dfs(int n, int index, int &count, vector<int> &visited) {
        if (index == n + 1) {
            count++;
            return;
        }

        for (int i = 1; i <= n; i++) {
            if (visited[i] == 0) {
                visited[i] = 1;
                if (i % index == 0 || index % i == 0) {
                    dfs(n, index + 1, count, visited);
                }
                visited[i] = 0;
            }
        }
    }
};

int main(int argc, char **argv) {
    Solution s;
    EXPECT_EQ(s.countArrangement(3), 3);
    EXPECT_EQ(s.countArrangement(2), 2);
    EXPECT_EQ(s.countArrangement(1), 1);
    return EXIT_SUCCESS;
}