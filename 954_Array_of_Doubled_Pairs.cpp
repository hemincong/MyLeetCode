#include <vector>
#include <unordered_map>
#include "AlgoUtils.h"

using namespace std;

class Solution {
public:
    bool canReorderDoubled(vector<int> &arr) {

        sort(arr.begin(), arr.end());
        unordered_map<int, int> m;

        for (auto &n: arr) {
            int k = 2 * n;
            if (n < 0) {
                if (m.find(k) != m.end() && m[k] != 0) {
                    m[k]--;
                } else {
                    m[n]++;
                }
            } else {
                if (m.find(n) != m.end() && m[n] != 0) {
                    m[n]--;
                } else {
                    m[k]++;
                }
            }
        }

        return all_of(m.begin(), m.end(), [](const auto &i) {
            return i.second == 0;
        });
    }
};

int main(int argc, char **argv) {
    Solution s;
    vector<int> arr_1{3, 1, 3, 6};
    EXPECT_FALSE(s.canReorderDoubled(arr_1));

    vector<int> arr_2{2, 1, 2, 6};
    EXPECT_FALSE(s.canReorderDoubled(arr_2));

    vector<int> arr_3{4, -2, 2, -4};
    EXPECT_TRUE(s.canReorderDoubled(arr_3));

    vector<int> arr_4{-5, -2};
    EXPECT_FALSE(s.canReorderDoubled(arr_4));

    vector<int> arr_5{2, 4, 0, 0, 8, 1};
    EXPECT_TRUE(s.canReorderDoubled(arr_5));

    vector<int> arr_6{1, 2, 1, -8, 8, -4, 4, -4, 2, -2};
    EXPECT_TRUE(s.canReorderDoubled(arr_6));

    return EXIT_SUCCESS;
}