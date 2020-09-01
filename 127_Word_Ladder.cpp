//
// Created by mincong.he on 2020/7/28.
//

#include <string>
#include <vector>
#include <map>
#include <queue>
#include <set>

#include "AlgoUtils.h"

using namespace std;


class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string> &wordList) {
        map<string, vector<string>> word_map;
        build_map(beginWord, wordList, word_map);

        auto ret = bfs(beginWord, endWord, word_map);
        return ret;
    }

private:
    static bool one_word_different(const string &w1, const string &w2) {
        if (w1.length() != w2.length()) return false;

        int count = 0;
        for (int i = 0; i < w1.length(); ++i) {
            if (w1[i] != w2[i]) count++;
            if (count > 1) return false;
        }
        return true;
    }

    static void build_map(const string &beginWord,
                          const vector<string> &wordList, map<string, vector<string>> &word_map) {
        word_map = map<string, vector<string>>();

        vector<string> word_list_add_beign(wordList);
        word_list_add_beign.push_back(beginWord);

        for (int i = 0; i < word_list_add_beign.size(); ++i) {
            for (int j = i + 1; j < word_list_add_beign.size(); ++j) {
                if (one_word_different(word_list_add_beign[i], word_list_add_beign[j])) {
                    word_map[word_list_add_beign[i]].push_back(word_list_add_beign[j]);
                    word_map[word_list_add_beign[j]].push_back(word_list_add_beign[i]);
                }
            }
        }

        //for (auto &wl : word_map) {
        //   std::cout << wl.first << ": ";
        //  for (auto &w : wl.second) {
        //     std::cout << w << " ";
        //}
        //std::cout << std::endl;
        //}
    }

    static int bfs(const string &beginWord, const string &endWord,
                   map<std::string, vector<string>> &word_map) {
        queue<pair<std::string, int>> q;
        set<string> visited;
        visited.insert(beginWord);
        q.push(make_pair(beginWord, 1));

        while (!q.empty()) {
            auto front_word = q.front().first;
            auto word_level = q.front().second;
            q.pop();

            if (front_word == endWord) {
                return word_level;
            }
            auto w_vec = word_map[front_word];
            for (const auto &w : w_vec) {
                // 没有走过
                if (visited.find(w) == visited.end()) {
                    q.push(make_pair(w, word_level + 1));
                    visited.insert(w);
                }
            }
        }

        return 0;
    }
};

int main(int argc, char **argv) {
    Solution s;
    vector<string> word_list_1{"hot", "dot", "dog", "lot", "log", "cog"};
    EXPECT_EQ(s.ladderLength("hit", "cog", word_list_1), 5);

    vector<string> word_list_2{"hot", "dot", "dog", "lot", "log"};
    EXPECT_EQ(s.ladderLength("hit", "cog", word_list_2), 0);

    vector<string> word_list_3{};
    EXPECT_EQ(s.ladderLength("hit", "cog", word_list_3), 0);

    vector<string> word_list_4{};
    EXPECT_EQ(s.ladderLength("", "", word_list_3), 1);

    return EXIT_SUCCESS;
}