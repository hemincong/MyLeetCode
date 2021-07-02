//
// Created by mincong.he on 2021/7/3.
//

#include <sstream>
#include <map>
#include "AlgoUtils.h"

using namespace std;

class Solution {
public:
    string frequencySort(string s) {
        std::map<char, int> char_map;
        for (auto &c : s) {
            auto iter = char_map.find(c);
            if (iter != char_map.end()) {
                iter->second++;
            } else {
                char_map[c] = 1;
            }
        }
        auto cmp = [](const pair<char, int> &p1, const pair<char, int> &p2) {
            return p1.second < p2.second;
        };
        std::priority_queue<pair<char, int>, std::vector<pair<char, int>>, decltype(cmp)> fq(cmp);
        for (auto &m : char_map) {
            fq.emplace(m);
        }
        std::stringstream ss;
        while (!fq.empty()) {
            for (int i = 0; i < fq.top().second; ++i) ss << fq.top().first;
            fq.pop();
        }
        return ss.str();
    }
};

int main(int argc, char **argv) {
    Solution s;
    std::cout << s.frequencySort("tree") << std::endl; // "eert" or "eetr"
    std::cout << s.frequencySort("cccaaa") << std::endl; // "cccaaa" or "aaaccc"
    std::cout << s.frequencySort("Aabb") << std::endl; // "bbAa" or "bbaA"
    return EXIT_SUCCESS;
}