//
// Created by mincong.he on 2019/10/5.
//

#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int wiggleMaxLength(vector<int> &nums) {
        if (nums.size() < 2) {
            return nums.size();
        }
        std::vector<int> ret;

        auto p = nums.begin();
        p++;
        auto b = nums.begin();

        while (p != nums.end()) {
            if (*p > *b) {
                ret.emplace_back(1);
            } else if (*p == *b) {
                //ret.emplace_back(0);
            } else {
                ret.emplace_back(-1);
            }

            b++;
            p++;
        }

        if (ret.empty()) return 1;

        int total = 2;
        auto r_p = ret.begin();
        r_p++;
        auto r_b = ret.begin();

        for (const auto &n: nums) {
            std::cout << n << " ";
        }
        std::cout << std::endl;

        for (const auto &n: ret) {
            std::cout << n << " ";
        }
        std::cout << std::endl;
        std::cout << std::endl;

        while (r_p != ret.end()) {
            if (*r_p != *r_b) {
                total++;
            }
            r_b++;
            r_p++;
        }

        return total;
    }
};

int main(int argc, char **argv) {
    std::vector<int> nums_1 = {1, 7, 4, 9, 2, 5}; // 6
    std::vector<int> nums_2 = {1, 17, 5, 10, 13, 15, 10, 5, 16, 8}; // 7
    std::vector<int> nums_3 = {1, 2, 3, 4, 5, 6, 7, 8, 9}; // 2
    std::vector<int> nums_4 = {0, 0}; // 1
    std::vector<int> nums_5 = {0, 0, 0}; // 1
    std::vector<int> nums_6 = {1, 0, 0}; // 2

    Solution solve;
    auto ret_1 = solve.wiggleMaxLength(nums_1);
    assert(ret_1 == 6);

    auto ret_2 = solve.wiggleMaxLength(nums_2);
    assert(ret_2 == 7);

    auto ret_3 = solve.wiggleMaxLength(nums_3);
    assert(ret_3 == 2);

    auto ret_4 = solve.wiggleMaxLength(nums_4);
    assert(ret_4 == 1);

    auto ret_5 = solve.wiggleMaxLength(nums_5);
    assert(ret_5 == 1);

    auto ret_6 = solve.wiggleMaxLength(nums_6);
    assert(ret_6 == 2);

    return EXIT_SUCCESS;
}
