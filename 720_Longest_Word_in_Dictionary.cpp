#include <vector>
#include "AlgoUtils.h"
#include <set>

using namespace std;

class Solution {
public:
    string longestWord(vector<string> &words) {

        std::sort(words.begin(), words.end(), [](const auto &s1, const auto &s2) {
            return s1 < s2;
        });

        set<string> s_pool;
        int longest_length = INT_MIN;
        string *ret = nullptr;

        for (auto &word: words) {
            int w_len = word.size();
            bool inserted = false;
            auto sub_word = word.substr(0, w_len - 1);
            if (w_len == 1 || s_pool.find(sub_word) != s_pool.end()) {
                s_pool.insert(word);
                inserted = true;
            }
            if (inserted && w_len > longest_length) {
                longest_length = w_len;
                ret = &word;
            }
        }

        return ret == nullptr ? "" : *ret;
    }
};

int main(int argc, char **argv) {
    Solution s;
    vector<string> words_0{"b", "br", "bre", "brea", "break", "breakf", "breakfa", "breakfas", "breakfast", "l", "lu",
                           "lun", "lunc", "lunch", "d", "di", "din", "dinn", "dinne", "dinner"};
    EXPECT_EQ(s.longestWord(words_0), "breakfast")

    vector<string> words_1{"w", "wo", "wor", "worl", "world"};
    EXPECT_EQ(s.longestWord(words_1), "world")

    vector<string> words_2{"a", "banana", "app", "appl", "ap", "apply", "apple"};
    EXPECT_EQ(s.longestWord(words_2), "apple")
    return EXIT_SUCCESS;
}