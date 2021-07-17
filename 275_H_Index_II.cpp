#include <vector>
#include "AlgoUtils.h"

using namespace std;

class Solution {
public:
    int hIndex(vector<int> &citations) {
        int l = 0;
        int n = citations.size();
        int r = n - 1;
        while (l < r) {
            int mid = l + ((r - l) >> 1);
            if (citations[mid] >= n - mid) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        if (citations[r] >= n - r) {
            return n - r;
        }
        return 0;
    }
};

int main(int argc, char **argv) {
    Solution s;
    vector<int> test_case_1{0, 1, 3, 5, 6};
    vector<int> test_case_2{1, 2, 100};
    EXPECT_EQ(s.hIndex(test_case_1), 3)
    EXPECT_EQ(s.hIndex(test_case_2), 2)
    return EXIT_SUCCESS;
}