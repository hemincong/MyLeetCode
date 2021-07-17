#include <vector>
#include <unordered_map>
#include "AlgoUtils.h"

using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs) {
        vector<vector<string>> ret;
        unordered_map<string, vector<string>> m;
        for (auto &s : strs) {
            auto key = s;
            sort(key.begin(), key.end());
            m[key].emplace_back(s);
        }
        ret.reserve(m.size());
        for (auto &p : m) {
            ret.emplace_back(p.second);
        }
        return ret;
    }
};

int main(int argc, char **argv) {
    Solution s;
    vector<string> test_case_1{"eat", "tea", "tan", "ate", "nat", "bat"};
    printMatrix(s.groupAnagrams(test_case_1));

    return EXIT_SUCCESS;
}