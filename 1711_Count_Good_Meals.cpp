#include <vector>
#include <unordered_map>
#include "AlgoUtils.h"

using namespace std;

class Solution {
public:
    int countPairs(vector<int> &deliciousness) {
        unordered_map<int, int> m;
        auto max_value = *std::max_element(deliciousness.begin(), deliciousness.end());
        auto max_sum = max_value * 2;
        int pairs = 0;
        for (auto &d : deliciousness) {
            for (int i = 1; i <= max_sum; i <<= 1) {
                if (m.find(i - d) != m.end()) {
                    pairs = (pairs + m[i - d]) % MOD;
                }
            }
            // 时机很重要 避免了重复
            m[d]++;
        }
        return pairs;
    }

private:
    static constexpr int MOD = 1000000007;

};

int main(int argc, char **argv) {
    Solution s;
    vector<int> test_case_1{1, 3, 5, 7, 9};
    EXPECT_EQ(s.countPairs(test_case_1), 4);

    vector<int> test_case_2{1, 1, 1, 3, 3, 3, 7};
    EXPECT_EQ(s.countPairs(test_case_2), 15);
    return EXIT_SUCCESS;
}