//
// Created by mincong.he on 2020/7/28.
//

#include <string>
#include <utility>
#include <vector>
#include <map>
#include <queue>

#include "AlgoUtils.h"

using namespace std;

class Solution {

    struct step_info {
        string node;
        string parent_node;
        int step_order;
    };

public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string> &wordList) {
        map<string, vector<string>> word_map;
        build_map(beginWord, wordList, word_map);
        map<string, vector<step_info>> si;
        bfs(beginWord, endWord, word_map, si);
        vector<vector<string>> ret;
        travel_all_path(beginWord, endWord, si, ret);
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
                          const vector<string> &wordList,
                          map<string, vector<string>> &word_map) {
        word_map = map<string, vector<string>>();

        vector<string> word_list_add_begin(wordList);
        word_list_add_begin.push_back(beginWord);

        for (int i = 0; i < word_list_add_begin.size(); ++i) {
            for (int j = i + 1; j < word_list_add_begin.size(); ++j) {
                if (one_word_different(word_list_add_begin[i], word_list_add_begin[j])) {
                    word_map[word_list_add_begin[i]].push_back(word_list_add_begin[j]);
                    word_map[word_list_add_begin[j]].push_back(word_list_add_begin[i]);
                }
            }
        }
    }

    static int bfs(const string &beginWord, const string &endWord,
                   map<std::string, vector<string>> &word_map,
                   map<string, vector<step_info>> &visited) {
        queue<string> next;
        visited.emplace(beginWord, std::move(vector<step_info>{{beginWord, "", 1}}));
        next.push(beginWord);

        while (!next.empty()) {
            auto n = next.front();
            next.pop();

            auto w_vec = word_map[n];
            for (const auto &w : w_vec) {
                // 没有走过
                if (visited.find(w) == visited.end()) {
                    next.emplace(w);
                    // 当前点的步数
                    // 所有的都是可以的
                    auto parent_step = visited[n][0].step_order;
                    visited[w] = vector<step_info>{{w, n, parent_step + 1}};
                } else {
                    // 走过，看看是不是最短的
                    auto old_step = visited[w][0].step_order;
                    auto parent_step = visited[n][0].step_order;
                    // 更新到最短路程
                    if (old_step > parent_step + 1) {
                        // 清掉
                        visited[w].clear();
                        visited[w].push_back({w, n, parent_step + 1});
                    } else if (old_step == parent_step + 1) {
                        visited[w].push_back({w, n, parent_step + 1});
                    }
                }
            }
        }

        return 0;
    }

    void travel_a_vec(const string &beginWord,
                      const map<string, vector<step_info>> &si,
                      vector<string> curr_list, // copy
                      vector<vector<string>> &ret
    ) {
        auto back_word = curr_list.back();
        if (back_word == beginWord) {
            std::reverse(curr_list.begin(), curr_list.end());
            ret.emplace_back(curr_list);
            return;
        }
        auto back_word_list = si.find(back_word);
        if (back_word_list != si.end()) {
            for (const auto &s : back_word_list->second) {
                auto tmp = curr_list;
                tmp.push_back(s.parent_node);
                travel_a_vec(beginWord, si, tmp, ret);
            }
        }
    }

    void travel_all_path(const string &beginWord, const string &endWord,
                         const map<string, vector<step_info>> &si,
                         vector<vector<string>> &ret) {
        auto curr_vec = vector<string>{endWord};
        travel_a_vec(beginWord, si, curr_vec, ret);
        sort( ret.begin(), ret.end() );
        ret.erase( unique( ret.begin(), ret.end() ), ret.end() );
    }
};

int main(int argc, char **argv) {
    Solution s;
    vector<string> word_list_1{"hot", "dot", "dog", "lot", "log", "cog"};
    auto ret_1 = s.findLadders("hit", "cog", word_list_1);
    for (const auto &c : ret_1) {
        for (const auto &w : c) {
            std::cout << w << " ";
        }
        std::cout << std::endl;
    }

    vector<string> word_list_2{"hot", "dot", "dog", "lot", "log"};
    auto ret_2 = s.findLadders("hit", "cog", word_list_2);
    for (const auto &c : ret_2) {
        for (const auto &w : c) {
            std::cout << w << " ";
        }
        std::cout << std::endl;
    }

    vector<string> word_list_3{"a", "b", "c"};
    auto ret_3 = s.findLadders("a", "c", word_list_3);
    for (const auto &c : ret_3) {
        for (const auto &w : c) {
            std::cout << w << " ";
        }
        std::cout << std::endl;
    }
    return EXIT_SUCCESS;
}