#include <vector>
#include <set>
#include "AlgoUtils.h"

using namespace std;

class Solution_1 {
public:
    int nthSuperUglyNumber(int n, vector<int> &primes) {
        priority_queue<unsigned long long, vector<unsigned long long>, greater<>> h;
        set<unsigned long long> visited;
        vector<int> ret(n + 1, 0);
        h.push(1);

        for (int i = 0; i < n; ++i) {
            auto top_1 = h.top();
            for (int p: primes) {
                unsigned long long new_top = top_1 * p;
                if (visited.count(new_top) == 0) {
                    visited.insert(new_top);
                    h.push(new_top);
                }
            }
            ret[i] = h.top();
            h.pop();
        }
        return ret[n - 1];
    }
};

class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int> &primes) {
        int p_size = primes.size();
        vector<int> dp(p_size, 0);
        vector<int> temp_ret(p_size, 1);
        vector<int> ret(n, 1);
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < p_size; j++) {
                temp_ret[j] = ret[dp[j]] * primes[j];
            }
            auto min = *min_element(temp_ret.begin(), temp_ret.end());
            // 一定要分开做，因为有等于的情况，这时候，所有等于的都要指针+1，避免会出现重复
            for (int j = 0; j < p_size; j++) {
                if (temp_ret[j] == min) {
                    dp[j]++;
                }
            }
            ret[i] = min;
        }
        return ret[n - 1];
    }
};

int main(int argc, char **argv) {
    Solution s;
    vector<int> test_case_1{2, 7, 13, 19};
    EXPECT_EQ(s.nthSuperUglyNumber(12, test_case_1), 32)
    vector<int> test_case_2{2, 3, 5};
    EXPECT_EQ(s.nthSuperUglyNumber(1, test_case_2), 1)
    vector<int> test_case_3{7, 19, 29, 37, 41, 47, 53, 59, 61, 79, 83, 89, 101, 103, 109, 127, 131, 137, 139, 157, 167,
                            179, 181, 199, 211, 229, 233, 239, 241, 251};
    EXPECT_EQ(s.nthSuperUglyNumber(100000, test_case_3), 1092889481)
    return EXIT_SUCCESS;
}