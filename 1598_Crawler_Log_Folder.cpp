#include <vector>
#include "AlgoUtils.h"

using namespace std;

class Solution {
public:
    int minOperations(vector<string>& logs) {
        int level = 0;
        for (auto &p: logs) {
            if (p == "../") {
                if (level > 0) --level;
            } else if (p == "./") {
                continue;
            } else {
                ++level;
            }
        }
        return level;

    }
};
int main(int argc, char **argv) {
    Solution s;
    return EXIT_SUCCESS;
}