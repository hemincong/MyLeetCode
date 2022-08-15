#include <vector>
#include "AlgoUtils.h"

using namespace std;

class Solution {
public:
    bool rotateString(string s, string goal) {
        return s.size() == goal.size() && (s + s).find(goal) != -1;
    }
};

int main(int argc, char **argv) {
    Solution s;
    return EXIT_SUCCESS;
}