#include <vector>
#include <list>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include "AlgoUtils.h"

using namespace std;

class AllOne {
public:
    AllOne() {

    }

    void inc(string key) {
        if (_nodes.count(key)) {
            auto curr = _nodes[key];
            auto next = std::next(curr);
            if (next == _l.end() || next->second > curr->second + 1) {
                auto new_set = unordered_set{key};
                _nodes[key] = _l.emplace(next, new_set, curr->second + 1);
            } else {
                next->first.emplace(key);
                _nodes[key] = next;
            }
            curr->first.erase(key);
            if (curr->first.empty()) {
                _l.erase(curr);
            }
        } else {
            if (_l.empty() || _l.begin()->second > 1) {
                auto new_set = unordered_set{key};
                _l.emplace_front(new_set, 1);
            } else {
                _l.begin()->first.emplace(key);
            }
            _nodes[key] = _l.begin();
        }
    }

    void dec(string key) {
        auto curr = _nodes[key];
        if (curr->second == 1) {
            _nodes.erase(key);
        } else {
            auto pre = std::prev(curr);
            if (curr == _l.begin() || pre->second < curr->second - 1) {
                auto new_set = unordered_set{key};
                _nodes[key] = _l.emplace(curr, new_set, curr->second - 1);
            } else {
                pre->first.emplace(key);
                _nodes[key] = pre;
            }
            curr->first.erase(key);
            if (curr->first.empty()) {
                _l.erase(curr);
            }
        }
    }

    string getMaxKey() {
        if (_l.empty()) return "";

        return *_l.rbegin()->first.begin();
    }

    string getMinKey() {
        if (_l.empty()) return "";

        return *_l.begin()->first.begin();
    }

private:
    typedef std::list<pair<unordered_set<string>, int>> word_list;
    word_list _l;
    unordered_map<string, word_list::iterator> _nodes;
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */

int main(int argc, char **argv) {
    AllOne allOne = AllOne();
    allOne.inc("hello");
    allOne.inc("hello");
    EXPECT_EQ(allOne.getMaxKey(), "hello"); // return "hello"
    EXPECT_EQ(allOne.getMinKey(), "hello"); // return "hello"
    allOne.inc("leet");
    EXPECT_EQ(allOne.getMaxKey(), "hello") // return "hello"
    EXPECT_EQ(allOne.getMinKey(), "leet") // return "leet"

    return EXIT_SUCCESS;
}