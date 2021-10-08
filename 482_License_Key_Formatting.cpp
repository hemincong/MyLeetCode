#include <vector>
#include "AlgoUtils.h"

using namespace std;

class Solution {
public:
    string licenseKeyFormatting(string s, int k) {
        if (s.empty()) return "";
        vector<char> buff;
        auto n = s.size();
        int count = 0;
        for (int i = n - 1; i >= 0; --i) {
            if (s[i] == '-') continue;
            if (count == k) {
                count = 0;
                buff.push_back('-');
            }
            count++;
            buff.push_back(std::toupper(s[i]));
        }
        std::reverse(buff.begin(), buff.end());
        buff.push_back('\0');
        return string(&buff.at(0));
    }
};

int main(int argc, char **argv) {
    Solution s;
    return EXIT_SUCCESS;
}