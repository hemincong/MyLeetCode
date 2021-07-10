#include <vector>
#include "AlgoUtils.h"

using namespace std;

class Solution {
public:
    int hIndex(vector<int> &citations) {
        std::sort(citations.begin(), citations.end(), less());
        auto n = citations.size();

        for (int i = 0; i < n; ++i) {
            int h = n - i;
            if (citations[i] >= h) {
                return h;
            }
        }
        return 0;
    }
};

int main(int argc, char **argv) {
    Solution s;
    vector<int> test_case_1{3, 0, 6, 1, 5};
    vector<int> test_case_2{1, 3, 1};
    EXPECT_EQ(s.hIndex(test_case_1), 3);
    EXPECT_EQ(s.hIndex(test_case_2), 1);
    return EXIT_SUCCESS;
}