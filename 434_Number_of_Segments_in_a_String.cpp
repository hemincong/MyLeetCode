#include <vector>
#include "AlgoUtils.h"

using namespace std;

class Solution {
public:
    int countSegments(string s) {
        if (s.empty()) return 0;
        auto n = s.size();
        int count = 0;
        for (int i = 0; i < n - 1; ++i) {
            if (s[i] != ' ' && s[i + 1] == ' ') count++;
        }
        if (s[n - 1] != ' ') count++;
        return count;
    }
};

int main(int argc, char **argv) {
    Solution s;
    EXPECT_EQ(s.countSegments("Hello, my name is John"), 5);
    EXPECT_EQ(s.countSegments("Hello"), 1);
    EXPECT_EQ(s.countSegments("love live! mu'sic forever"), 4)
    EXPECT_EQ(s.countSegments(""), 0);
    EXPECT_EQ(s.countSegments(" "), 0);

    return EXIT_SUCCESS;
}