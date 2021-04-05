//
// Created by mincong.he on 2021/4/4.
//

#include <vector>
#include <unordered_map>
#include "AlgoUtils.h"

using namespace std;

class Solution {
public:
    int numRabbits(vector<int> &answers) {
        auto m = unordered_map<int, int>();
        int sum = 0;
        for (auto a :answers) {
            if (m.find(a) != m.end()) {
                m[a]++;
            } else {
                m[a] = 1;
            }
        }
        for (auto &[k, v] : m) {
            sum += (v + k) / (k + 1) * (k + 1);
        }
        return sum;
    }
};

int main(int argc, char **argv) {
    Solution s;
    vector<int> test_case_1{1, 1, 2};
    vector<int> test_case_2{10, 10, 10};
    vector<int> test_case_3;
    vector<int> test_case_4{1, 0, 1, 0, 0};
    vector<int> test_case_5{0, 0, 1, 1, 1};
    EXPECT_EQ(s.numRabbits(test_case_1), 5);
    EXPECT_EQ(s.numRabbits(test_case_2), 11);
    EXPECT_EQ(s.numRabbits(test_case_3), 0);
    EXPECT_EQ(s.numRabbits(test_case_4), 5);
    EXPECT_EQ(s.numRabbits(test_case_5), 6);
    return EXIT_SUCCESS;
}