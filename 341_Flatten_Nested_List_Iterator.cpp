#include <vector>

using namespace std;
/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

class NestedIterator {
public:
    NestedIterator(vector<NestedInteger> &nestedList) : _index(0) {
        dfs(nestedList);
    }

    int next() {
        return _nums[_index++];
    }

    bool hasNext() {
        return _index < _nums.size();
    }
private:
    void dfs(const vector<NestedInteger> &nestedList) {
        for (const auto & n : nestedList) {
            if (n.isInteger()) {
                _nums.push_back(n.getInteger());
            } else {
                dfs(n.getList());
            }
        }
    }
    vector<int> _nums;
    int _index;
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */