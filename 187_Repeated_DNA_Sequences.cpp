//
// Created by mincong.he on 2020/7/21.
//

#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_map<string, int> m;
        for (int i = 0; i + 9 < s.length(); i++) {
            auto substr = s.substr(i, 10);
            m[substr]++;
        }
        vector<string> res;
        for (const auto& w : m) {
            if (w.second > 1) res.push_back(w.first);
        }
        return res;
    }
};

// TODO: solusion 2 bit set

int main(int argc, char **argv) {
    Solution s;
    auto ret = s.findRepeatedDnaSequences("AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT");
    for (auto &r : ret) {
        std::cout << r << ",";
    }
    std::cout << std::endl;
    return EXIT_SUCCESS;
}