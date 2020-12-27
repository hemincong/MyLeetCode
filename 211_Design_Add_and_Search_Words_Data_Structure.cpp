//
// Created by mincong.he on 2020/12/27.
//

#include <string>
#include "AlgoUtils.h"

using namespace std;
#define TRIE_MAX_CHAR_NUM 26

struct TrieNode {
    TrieNode *child[TRIE_MAX_CHAR_NUM]{};
    bool is_end;

    TrieNode() : is_end(false) {
        memset(child, 0, TRIE_MAX_CHAR_NUM);
    }

    ~TrieNode() {
        for (auto &i : child) {
            delete i;
            i = nullptr;
        }
    }
};

class WordDictionary {
public:
    /** Initialize your data structure here. */
    WordDictionary() {
        memset(_root, NULL, TRIE_MAX_CHAR_NUM);
    }

    ~WordDictionary() {
        for (auto &i : _root) {
            if (i) {
                delete (i);
                i = nullptr;
            }
        }
    }

    /** Adds a word into the data structure. */
    void addWord(string word) {
        if (word.empty()) return;
        auto c = word.c_str();
        auto i = *c - 'a';
        if (!_root[i]) _root[i] = new TrieNode;
        TrieNode *last = _root[i];
        auto _p = _root[i]->child;
        c++;
        while (*c != '\0') {
            i = *c - 'a';
            if (!_p[i]) _p[i] = new TrieNode();
            last = _p[i];
            _p = _p[i]->child;
            c++;
        }
        last->is_end = true;
    }

    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search_sub_string(const char *c, TrieNode *node) {
        if (!node) return false;
        if (*c == '\0') {
            return node->is_end;
        }

        bool ret = false;
        if (*c == '.') {
            for (auto sub_node : node->child) {
                if (sub_node) {
                    if (search_sub_string(c + 1, sub_node)) {
                        ret = true;
                        break;
                    }
                }
            }
            return ret;
        }

        auto _p = node->child;
        int i = *c - 'a';
        if (!_p[i]) return false;
        return search_sub_string(c + 1, _p[i]);
    }

    bool search(string word) {
        if (word.empty()) return true;
        auto c = word.c_str();
        if (*c == '.') {
            bool ret = false;
            for (auto sub_node : _root) {
                if (sub_node && search_sub_string(c + 1, sub_node)) {
                    ret = true;
                    break;
                }
            }
            return ret;
        } else {
            auto i = *c - 'a';
            auto _p = _root[i];
            if (_p)
                return search_sub_string(c + 1, _p);
            return false;
        }
    }

private:
    TrieNode *_root[TRIE_MAX_CHAR_NUM]{};
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
int main(int argc, char **argv) {
    WordDictionary wordDictionary;
    wordDictionary.addWord("bad");
    wordDictionary.addWord("dad");
    wordDictionary.addWord("mad");
    EXPECT_FALSE(wordDictionary.search("pad")); // return False
    EXPECT_TRUE(wordDictionary.search("bad")); // return True
    EXPECT_TRUE(wordDictionary.search(".ad")); // return True
    EXPECT_TRUE(wordDictionary.search("b..")); // return True

    WordDictionary wordDictionary_2;
    wordDictionary_2.addWord("a");
    wordDictionary_2.addWord("a");
    EXPECT_TRUE(wordDictionary_2.search("."));
    EXPECT_TRUE(wordDictionary_2.search("a"));
    EXPECT_FALSE(wordDictionary_2.search("aa"));
    EXPECT_TRUE(wordDictionary_2.search("a"));
    EXPECT_FALSE(wordDictionary_2.search(".a"));
    EXPECT_FALSE(wordDictionary_2.search("a."));

    WordDictionary wordDictionary_3;
    wordDictionary_3.addWord("a");
    wordDictionary_3.addWord("ab");
    EXPECT_TRUE(wordDictionary_3.search("a"));
    EXPECT_TRUE(wordDictionary_3.search("a."));
    EXPECT_TRUE(wordDictionary_3.search("ab"));
    EXPECT_FALSE(wordDictionary_3.search(".a"));
    EXPECT_TRUE(wordDictionary_3.search(".b"));
    EXPECT_FALSE(wordDictionary_3.search("ab."));
    EXPECT_TRUE(wordDictionary_3.search("."));
    EXPECT_TRUE(wordDictionary_3.search(".."));

    WordDictionary wordDictionary_4;
    wordDictionary_4.addWord("at");
    wordDictionary_4.addWord("and");
    wordDictionary_4.addWord("an");
    wordDictionary_4.addWord("add");
    EXPECT_FALSE(wordDictionary_4.search("a"));
    EXPECT_FALSE(wordDictionary_4.search(".at"));
    wordDictionary_4.addWord("bat");
    EXPECT_TRUE(wordDictionary_4.search(".at"));
    EXPECT_TRUE(wordDictionary_4.search("an."));
    EXPECT_FALSE(wordDictionary_4.search("a.d."));
    EXPECT_FALSE(wordDictionary_4.search("b."));
    EXPECT_TRUE(wordDictionary_4.search("a.d"));
    EXPECT_FALSE(wordDictionary_4.search("."));
    return EXIT_SUCCESS;
}

