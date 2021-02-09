//
// Created by mincong.he on 2021/2/9.
//
#include "AlgoUtils.h"
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    int subarraysWithKDistinct(vector<int> &A, int K) {
        // 计算少于等于K的
        auto d_1 = _sub_dist(A, K);
        // 计算少于等于K-1
        auto d_2 = _sub_dist(A, K - 1);
        // 所以就恰好
        return d_1 - d_2;
    }

private:
    int _sub_dist(const vector<int> &A, int K) {
        auto n = A.size();
        if (n == 0) return 0;
        map<int, int> count_map;
        int count = 0;
        int j = 0;
        for (int i = 0; i < n; ++i) {
            if (count_map.find(A[i]) != count_map.end()) {
                count_map[A[i]]++;
            } else {
                count_map[A[i]] = 1;
            }

            while (count_map.size() > K) {
                count_map[A[j]]--;
                auto c = count_map[A[j]];
                if (c == 0) count_map.erase(A[j]);
                j++;
            }
            // 这个区域多少个数组，都是少于K的，注意，这是小于都包含了
            count += i - j + 1;
        }
        return count;
    }
};

int main(int argc, char **argv) {
    Solution s;
    vector<int> test_case_1{1, 2, 1, 2, 3};
    EXPECT_EQ(s.subarraysWithKDistinct(test_case_1, 2), 7);

    vector<int> test_case_2{1, 2, 1, 3, 4};
    EXPECT_EQ(s.subarraysWithKDistinct(test_case_2, 3), 3);
    return EXIT_SUCCESS;
}