//
// Created by mincong.he on 2021/3/7.
//
#include <string>
#include <vector>
#include "AlgoUtils.h"

using namespace std;

class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ret;
        vector<string> part;
        auto n = s.size();
        _mark = vector<vector<int>>(n, vector<int>(n, 0));
        dfs(ret, part, s, 0);
        return ret;
    }

private:
    void dfs(vector<vector<string>> &ret, vector<string> &part, const string &s, int i) {
        auto n = s.size();
        if (i == n) {
            ret.push_back(part);
        }

        for (int j = i; j < n; j++) {
            if (isPalindrome(s, i, j)) {
                part.push_back(s.substr(i, j - i + 1));
                dfs(ret, part, s, j + 1);
                part.pop_back();
            }
        }
    }

    bool isPalindrome(const string &s, int i, int j) {
        if (_mark[i][j] == -1) {
            return false;
        } else if (_mark[i][j] == 1) {
            return true;
        }

        if (i >= j) {
            _mark[i][j] = 1;
            return true;
        }
        if (s[i] != s[j]) {
            _mark[i][j] = -1;
            return false;
        }
        return isPalindrome(s, i + 1, j - 1);
    }

    vector<vector<int>> _mark;
};

int main(int argc, char **argv) {
    Solution s;
    printMatrix(s.partition("aab"));
    printMatrix(s.partition("a"));
    return EXIT_SUCCESS;
}