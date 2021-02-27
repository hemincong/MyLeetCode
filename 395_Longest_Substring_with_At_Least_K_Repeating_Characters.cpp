#include "AlgoUtils.h"
#include <unordered_map>
#include <sstream>

using namespace std;

class Solution {
public:
    int longestSubstring(string s, int k) {
        if (s.size() == 0) return 0;
        if (s.size() < k) return 0;

        unordered_map<char, int> char_count;
        for (const auto &c :s) {
            char_count[c]++;
        }

        for (const auto c_p : char_count) {
            if (c_p.second < k) {
                vector<string> splits;
                std::istringstream iss(s);
                string substring;
                while (getline(iss, substring, c_p.first)) {
                    splits.push_back(substring);
                }
                int ret = 0;
                for (auto &split : splits) {
                    auto sub_ret = longestSubstring(split, k);
                    if (ret < sub_ret) ret = sub_ret;
                }
                return ret;
            }
        }
        return s.size();
    }
};

int main(int argc, char **argv) {
    Solution s;
    EXPECT_EQ(s.longestSubstring("aaabb", 3), 3)
    EXPECT_EQ(s.longestSubstring("ababbc", 2), 5)
    return EXIT_SUCCESS;
}