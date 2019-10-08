//
// Created by mincong.he on 2019/10/7.
//

#include <vector>

using namespace std;

class Solution {
public:
    /*
    int jump(vector<int> &nums) {
        auto tmp = vector<int>(nums.size(), 0);

        int n_p = nums.size() - 2;
        int s = nums.size();

        tmp.back() = 1;

        while (n_p >= 0) {
            auto can_jump = nums.at(n_p);
            int less_step = INT32_MAX;
            bool jump = false;
            for (int i = 0; i <= can_jump && n_p + i < s; i++) {
                auto step = tmp.at(n_p + i);
                if (step < less_step && step != 0) {
                    less_step = step;
                    jump = true;
                }
            }
            if (jump) tmp[n_p] = less_step + 1;
            n_p--;
        }

        for (auto &n : tmp) {
            std::cout << n << " ";
        }
        std::cout << std::endl;

        if (tmp.at(0) != 0)
            return tmp.at(0) - 1;
        return 0;
    }
     */ // timeout

    int jump(vector<int> &nums) {
        if (nums.size() < 2) {
            return 0;
        }
        int jump = 1;
        int current_max_jump = nums[0];
        int max_jump_in_step = nums[0];

        for (int i = 1; i < nums.size(); i++) {
            // 已经要过这步最大能跳的范围
            if (i > current_max_jump) {
                // 必须跳，然后将这步之内能跳的最大范围，更新到下一步
                jump++;
                current_max_jump = max_jump_in_step;
            }

            if (nums[i] + i > max_jump_in_step) {
                // 顺便更新在这步只能能最远跳的目标
                max_jump_in_step = nums[i] + i;
            }
        }

        return jump;
    }
};

int main(int argc, char **argv) {
    Solution solve;
    std::vector<int> nums_1 = {2, 3, 1, 1, 4};
    assert(solve.jump(nums_1) == 2);

    return EXIT_SUCCESS;
}