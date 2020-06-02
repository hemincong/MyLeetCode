//
// Created by mincong.he on 2020/6/2.
//

#include <vector>
#include <iostream>
#include <map>

using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs) {
        vector<vector<string>> ret;

        map<vector<int>, vector<string>> map;
        for (const auto &word : strs) {
            auto vec = word_to_vec(word);
            map[vec].push_back(word);
        }

        ret.reserve(map.size());
        for (auto &pair: map) {
            ret.emplace_back(pair.second);
        }

        return ret;
    }

private:
    static vector<int> word_to_vec(const string &word) {
        vector<int> ret(26, 0);
        for (const auto &c : word) {
            ret.at(c - 'a')++;
        }

        return ret;
    }
};

int main(int argc, char **argv) {
    vector<string> test_case_1{"eat", "tea", "tan", "ate", "nat", "bat"};
    vector<string> test_case_2{"hos", "boo", "nay", "deb", "wow", "bop", "bob", "brr", "hey", "rye", "eve", "elf",
                               "pup", "bum", "iva", "lyx", "yap", "ugh", "hem", "rod", "aha", "nam", "gap", "yea",
                               "doc", "pen", "job", "dis", "max", "oho", "jed", "lye", "ram", "pup", "qua", "ugh",
                               "mir", "nap", "deb", "hog", "let", "gym", "bye", "lon", "aft", "eel", "sol", "jab"};
    Solution solution;
    auto ret_1 = solution.groupAnagrams(test_case_1);
    auto ret_2 = solution.groupAnagrams(test_case_2);
    std::cout << "[" << std::endl;
    for (const auto &group: ret_2) {
        std::cout << "[";
        for (const auto &w: group) {
            std::cout << "\"" << w << "\",";
        }
        std::cout << "],";
    }
    std::cout << "]" << std::endl;

    return EXIT_SUCCESS;
}

