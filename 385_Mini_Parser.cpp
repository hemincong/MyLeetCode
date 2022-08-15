#include <vector>
#include <string>
#include "AlgoUtils.h"

using namespace std;


// this is the interface that allows for creating nested lists.
// you should not implement it, or speculate about its implementation
class NestedInteger {
public:
    // constructor initializes an empty nested list.
    NestedInteger() = default;

    // constructor initializes a single integer.
    NestedInteger(int value) : integer_(value) {
    };

    // return true if this nestedinteger holds a single integer, rather than a nested list.
    bool isInteger() const {
        return list_.empty();
    };

    // return the single integer that this nestedinteger holds, if it holds a single integer
    // the result is undefined if this nestedinteger holds a nested list
    int getInteger() const {
        return integer_;
    };

    // set this nestedinteger to hold a single integer.
    void setInteger(int value) {
        integer_ = value;
    };

    // set this nestedinteger to hold a nested list and adds a nested integer to it.
    void add(const NestedInteger &ni) {
        list_.emplace_back(ni);
    };

    // return the nested list that this nestedinteger holds, if it holds a nested list
    // the result is undefined if this nestedinteger holds a single integer
    const vector<NestedInteger> &getList() const {
        return list_;
    }

private:
    int integer_;
    vector<NestedInteger> list_;
};

class Solution {
public:
    NestedInteger deserialize(string s) {
        if(s.empty()) return NestedInteger();
        if(s[0]!='[')  return NestedInteger(stoi(s));
        if(s.size()<=2) return NestedInteger();
        NestedInteger res;
        int start=1,cnt=0;
        for (int i=1;i<s.size();i++){
            if(cnt==0&&(s[i]==','||i==s.size()-1)){
                res.add(deserialize(s.substr(start,i-start)));
                start=i+1;
            }
            else if(s[i]=='[') cnt++;
            else if(s[i]==']') cnt--;
        }
        return res;
    }
};

int main(int argc, char **argv) {
    Solution s;
    auto ni = s.deserialize("324");
    EXPECT_TRUE(ni.isInteger());
    EXPECT_EQ(ni.getInteger(), 324);
    Solution s2;
    auto ni2 = s2.deserialize("[123,[456,[789]]]");
    EXPECT_FALSE(ni2.isInteger());
    EXPECT_EQ(ni2.getInteger(), 123);

    return EXIT_SUCCESS;
}