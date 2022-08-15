#include <vector>
#include "AlgoUtils.h"

using namespace std;

class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        return max(get_diff(answerKey, k, 'T'), get_diff(answerKey, k, 'F'));
    }

private:
    int get_diff(const string &answerKey, int k, char c) {
        int n = answerKey.size();
        int j = 0;
        int count = 0;
        int ret = 0;
        for (int i = 0; i < n; i++) {
            if (answerKey[i] == c) count++;
            while (count > k) {
                if (answerKey[j] == c) count--;
                j++;
            }

            ret = max(i - j + 1, ret);
        }
        return ret;
    }
};

int main(int argc, char **argv) {
    Solution s;
    EXPECT_EQ(s.maxConsecutiveAnswers("TTFF", 2), 4)
    EXPECT_EQ(s.maxConsecutiveAnswers("TFFT", 1), 3)
    EXPECT_EQ(s.maxConsecutiveAnswers("TTFTTFTT", 1), 5)
    return EXIT_SUCCESS;
}