#include <vector>
#include "AlgoUtils.h"

using namespace std;

class Solution {
public:
    vector<int> goodDaysToRobBank(vector<int> &security, int time) {
        auto n= security.size();
        if (n <= time * 2) return {};
        vector<int> ret;
        vector<int> left(n, 0);
        vector<int> right(n, 0);
        for (int i = 1; i < n; ++i) {
            if (security[i] <= security[i - 1]) {
                left[i] = left[i - 1] + 1;
            }
        }
        for (int i = n - 2; i >= 0; --i) {
            if (security[i] <= security[i + 1]) {
                right[i] = right[i + 1] + 1;
            }
        }
        for (int i = 0; i < n; ++i) {
            if (left[i] >= time && right[i] >= time) {
                ret.push_back(i);
            }
        }
        return ret;
    }
};

int main(int argc, char **argv) {
    Solution s;
    vector<int> test_case_1{5, 3, 3, 3, 5, 6, 2};
    vector<int> ret_1{2, 3};
    assertArray(s.goodDaysToRobBank(test_case_1, 2), ret_1);

    vector<int> test_case_2{1, 1, 1, 1, 1};
    vector<int> ret_2{0, 1, 2, 3, 4};
    assertArray(s.goodDaysToRobBank(test_case_2, 0), ret_2);

    vector<int> test_case_3{1, 2, 3, 4, 5, 6};
    vector<int> ret_3{};
    assertArray(s.goodDaysToRobBank(test_case_3, 2), ret_3);

    vector<int> test_case_4{1};
    vector<int> ret_4{};
    assertArray(s.goodDaysToRobBank(test_case_4, 5), ret_4);
    return EXIT_SUCCESS;
}