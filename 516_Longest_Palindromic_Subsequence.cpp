#include "AlgoUtils.h" 

#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int longestPalindromeSubseq(string s) {
		auto n = s.size();
		vector<vector<int>> dp(n, vector<int>(n, 0));
		for (int i = n - 1; i >= 0; --i) {
			dp[i][i] = 1;
			for (int j = i + 1; j < n; j++) {
				if (s[i] == s[j]) {
					dp[i][j] = dp[i + 1][j - 1] + 2;
				} else {
					dp[i][j] = max(dp[i + 1][j], dp[i][j -1]);
				}
			}
		}
		return dp[0][n - 1];
    }
};

int main(int argc, char** argv) {
	Solution s;
	EXPECT_EQ(s.longestPalindromeSubseq("bbbab"), 4);
	EXPECT_EQ(s.longestPalindromeSubseq("cbbd"), 2);
	EXPECT_EQ(s.longestPalindromeSubseq("a"), 1);
	EXPECT_EQ(s.longestPalindromeSubseq("aaa"), 3);
	return EXIT_SUCCESS;
}
