#include <vector>
#include "AlgoUtils.h"

using namespace std;

class Solution {
public:
    bool winnerOfGame(string colors) {
        int A_count = 0;
        int B_count = 0;
        int A_can_be_removed = 0;
        int B_can_be_removed = 0;

        for (auto c: colors) {
            if (c == 'A') {
                A_count++;
                if (A_count > 2) {
                    A_can_be_removed++;
                }
                B_count = 0;
            } else {
                B_count++;
                if (B_count > 2) {
                    B_can_be_removed++;
                }
                A_count = 0;
            }
        }
        return A_can_be_removed > B_can_be_removed;
    }
};
int main(int argc, char **argv) {
    Solution s;
    return EXIT_SUCCESS;
}