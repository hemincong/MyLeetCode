//
// Created by mincong.he on 2019/10/7.
//

#include <vector>

using namespace std;

class Solution {
public:
    bool canJump(vector<int> &nums) {
        auto tmp = vector<int>(nums.size(), 0);

        int n_p = nums.size() - 1;
        tmp.back() = 1;

        while (n_p >= 0) {
            auto can_jump = nums.at(n_p);
            for (int i = 0; i <= can_jump; i++) {
                if (tmp.at(n_p + i) == 1) {
                    tmp[n_p] = 1;
                    break;
                }
            }
            n_p--;
        }

        return tmp.at(0) == 1;
    }
};

int main(int argc, char **argv) {
    Solution solve;
    std::vector<int> nums_1 = {2, 3, 1, 1, 4};
    assert(solve.canJump(nums_1));

    std::vector<int> nums_2 = {3, 2, 1, 0, 4};
    assert(!solve.canJump(nums_2));

    return EXIT_SUCCESS;
}