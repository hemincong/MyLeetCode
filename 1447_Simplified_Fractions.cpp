#include <vector>
#include <string>
#include <set>
#include <numeric>

#include "AlgoUtils.h"

using namespace std;

class Solution {
public:
    vector<string> simplifiedFractions(int n) {
        set<pair<int, int>> s;
        for (int i = 1; i <= n ; ++i) {
            for (int j = 1; j < i; j++) {
                auto g = gcd(i, j);
                if (g == 1) {
                    s.insert({j, i});
                }
            }
        }
        vector<string> ret;
        char buff[32] = {'\0'};
        for (const auto&p : s) {
            memset(buff, '\0', 32);
            sprintf(buff, "%d/%d", p.first, p.second);
            ret.emplace_back(buff);
        }
        return ret;
    }
};

int main(int argc, char** argv) {
    Solution s;
    vector<string> ret_1{"1/2"};
    vector<string> ret_2{"1/2","1/3","2/3"};
    vector<string> ret_3{"1/2","1/3","1/4","2/3","3/4"};
    assertArray(s.simplifiedFractions(2), ret_1);
    assertArray(s.simplifiedFractions(3), ret_2);
    assertArray(s.simplifiedFractions(4), ret_3);
    return EXIT_SUCCESS;
}

