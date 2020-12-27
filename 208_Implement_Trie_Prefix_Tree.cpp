//
// Created by mincong.he on 2020/12/24.
//

#include "AlgoUtils.h"

#include <string>

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

class Trie {
public:
    /** Initialize your data structure here. */
    Trie() {
        memset(_root, NULL, TRIE_MAX_CHAR_NUM);
    }

    ~Trie() {
        for (auto &i : _root) {
            if (i) {
                delete (i);
                i = nullptr;
            }
        }
    }

    /** Inserts a word into the trie. */
    void insert(string word) {
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

    /** Returns if the word is in the trie. */
    bool search(string word) {
        if (word.empty()) return true;
        auto c = word.c_str();
        auto i = *c - 'a';
        if (!_root[i]) return false;
        TrieNode *last = _root[i];
        auto _p = last->child;
        c++;
        while (*c != '\0' && _p) {
            i = *c - 'a';
            if (!_p[i]) return false;
            last = _p[i];
            _p = _p[i]->child;
            c++;
        }
        if (*c != '\0') return false;
        if (!last->is_end) return false;
        return true;
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        if (prefix.empty()) return true;
        auto c = prefix.c_str();
        auto i = *c - 'a';
        if (!_root[i]) return false;
        auto _p = _root[i]->child;
        c++;
        while (*c != '\0' && _p) {
            i = *c - 'a';
            if (!_p[i]) return false;
            _p = _p[i]->child;
            c++;
        }
        if (*c != '\0') return false;
        return true;
    }

private:
    TrieNode *_root[TRIE_MAX_CHAR_NUM]{};
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */

int main(int argc, char **argv) {
    Trie trie_tree;
    trie_tree.insert("abcde");
    EXPECT_TRUE(trie_tree.search("abcde"))
    EXPECT_TRUE(trie_tree.startsWith("abc"))
    EXPECT_FALSE(trie_tree.startsWith("abcdef"))
    EXPECT_TRUE(trie_tree.startsWith("abcde"))
    trie_tree.insert("apple");
    EXPECT_TRUE(trie_tree.search("apple"))
    EXPECT_FALSE(trie_tree.search("app"))
    EXPECT_TRUE(trie_tree.startsWith("app"))
    trie_tree.insert("app");
    EXPECT_TRUE(trie_tree.search("app"))
    Trie trie_tree_2;
    trie_tree_2.insert("app");
    trie_tree_2.insert("apple");
    trie_tree_2.insert("beer");
    trie_tree_2.insert("add");
    trie_tree_2.insert("jam");
    trie_tree_2.insert("rental");
    EXPECT_FALSE(trie_tree_2.search("apps"))
    EXPECT_TRUE(trie_tree_2.search("app"))
    EXPECT_FALSE(trie_tree_2.search("ad"))
    EXPECT_FALSE(trie_tree_2.search("applepie"))
    EXPECT_FALSE(trie_tree_2.search("rest"))
    EXPECT_FALSE(trie_tree_2.search("jan"))
    EXPECT_FALSE(trie_tree_2.search("rent"))
    EXPECT_TRUE(trie_tree_2.search("beer"))
    EXPECT_TRUE(trie_tree_2.startsWith("jam"))
    EXPECT_FALSE(trie_tree_2.startsWith("apps"))
    EXPECT_TRUE(trie_tree_2.startsWith("app"))
    EXPECT_TRUE(trie_tree_2.startsWith("ad"))
    EXPECT_FALSE(trie_tree_2.startsWith("applepie"))
    EXPECT_FALSE(trie_tree_2.startsWith("rest"))
    EXPECT_FALSE(trie_tree_2.startsWith("jan"))
    EXPECT_TRUE(trie_tree_2.startsWith("rent"))
    EXPECT_TRUE(trie_tree_2.startsWith("beer"))
    EXPECT_TRUE(trie_tree_2.startsWith("jam"))
    return EXIT_SUCCESS;
}

