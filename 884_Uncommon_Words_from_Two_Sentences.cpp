//
// Created by mincong.he on 2022/1/30.
//

#include <vector>
#include <map>
#include "AlgoUtils.h"

using namespace std;

class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        std::map<string, int> m;
        gen_map(m, s1);
        gen_map(m, s2);
        vector<string> ret;
        for (const auto &p: m) {
            if (p.second == 1) {
                ret.emplace_back(p.first);
            }
        }
        return ret;
    }

    void gen_map(std::map<string, int> &m, const std::string &s) {
        vector<char> s_temp;
        for (char i: s) {
            if (i == ' ') {
                s_temp.emplace_back('\0');
                m[std::string(s_temp.data())]++;
                s_temp.clear();
            } else {
                s_temp.emplace_back(i);
            }
        }
        s_temp.emplace_back('\0');
        if (!s_temp.empty()) m[s_temp.data()]++;
    }
};

class Solution_2 {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        auto m1 = gen_map(s1);
        auto m2 = gen_map(s2);
        vector<string> ret;
        for (const auto &p: m1) {
            if (p.second == 1 && m2.find(p.first) == m2.end()) {
                ret.emplace_back(p.first);
            }
        }
        for (const auto &p: m2) {
            if (p.second == 1 && m1.find(p.first) == m1.end()) {
                ret.emplace_back(p.first);
            }
        }
        return ret;
    }

    std::map<string, int> gen_map(const std::string &s) {
        vector<char> s_temp;
        std::map<std::string, int> m;
        for (char i: s) {
            if (i == ' ') {
                s_temp.emplace_back('\0');
                m[std::string(s_temp.data())]++;
                s_temp.clear();
            } else {
                s_temp.emplace_back(i);
            }
        }
        s_temp.emplace_back('\0');
        if (!s_temp.empty()) m[s_temp.data()]++;
        return m;
    }
};

int main(int argc, char **argv) {
    Solution s;
    printArray(s.uncommonFromSentences("this apple is sweet", "this apple is sour"));
    std::cout << std::endl;
    printArray(s.uncommonFromSentences("apple apple", "banana"));

    return EXIT_SUCCESS;
}