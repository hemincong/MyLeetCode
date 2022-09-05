//
// Created by mincong.he on 2022/9/1.
//
#include "AlgoUtils.h"
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> finalPrices(vector<int> &prices) {
        stack<int> s;
        vector<int> ret(prices.size(), 0);
        for (int i = prices.size() - 1; i >= 0; i--) {
            while (!s.empty() && s.top() > prices[i]) {
                s.pop();
            }

            if (s.empty()) {
                ret[i] = prices[i];
            } else {
                ret[i] = prices[i] - s.top();
            }

            if (s.empty() || prices[i] > s.top()) {
                s.push(prices[i]);
            }
        }
        return ret;
    }
};

int main(int argc, char **argv) {
    Solution s;
    vector<int> test_case_1{8, 4, 6, 2, 3};
    vector<int> ret_1{4, 2, 4, 2, 3};
    assertArray(s.finalPrices(test_case_1), ret_1);

    vector<int> test_case_2{1, 2, 3, 4, 5};
    vector<int> ret_2{1, 2, 3, 4, 5};
    assertArray(s.finalPrices(test_case_2), ret_2);

    vector<int> test_case_3{10, 1, 1, 6};
    vector<int> ret_3{9, 0, 1, 6};
    assertArray(s.finalPrices(test_case_3), ret_3);

    return EXIT_SUCCESS;
}