#include <vector>
#include "AlgoUtils.h"

using namespace std;

class Solution {
public:
    string destCity(vector<vector<string>> &paths) {
        std::unordered_set<string> from_citys;
        std::unordered_set<string> to_citys;
        for (const auto &p: paths) {
            auto from = p[0];
            auto to = p[1];
            from_citys.insert(from);
            to_citys.insert(to);
        }

        for (const auto &c: to_citys) {
            if (from_citys.find(c) == from_citys.end()) return c;
        }
        return "";
    }
};

int main(int argc, char **argv) {
    Solution s;
    return EXIT_SUCCESS;
}