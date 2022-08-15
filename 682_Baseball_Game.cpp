#include <vector>
#include <numeric>
#include "AlgoUtils.h"

using namespace std;

class Solution {
public:
    int calPoints(vector<string>& ops) {
        vector<int> ret;
        for (const auto& s: ops) {
            if (s == "D") {
                ret.emplace_back(ret[ret.size() - 1] * 2);
            } else if (s == "C") {
                ret.pop_back();
            } else if (s == "+") {
                ret.emplace_back(ret[ret.size() - 1] + ret[ret.size() - 2]);
            } else {
                ret.emplace_back(stoi(s));
            }
        }
        return accumulate(ret.begin(), ret.end(), 0);
    }
};

int main(int argc, char **argv) {
    Solution s;
    vector<string> ops_1{"5","2","C","D","+"};
    EXPECT_EQ(s.calPoints(ops_1), 30);

    vector<string> ops_2{"5","-2","4","C","D","9","+","+"};
    EXPECT_EQ(s.calPoints(ops_2), 27);

    return EXIT_SUCCESS;
}