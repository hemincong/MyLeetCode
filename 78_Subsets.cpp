//
// Created by mincong.he on 2019/10/22.
//

#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<vector<int>> subsets(vector<int> &nums) {
        std::vector<std::vector<int>> result;
        std::vector<int> item;
        result.push_back(item);
        generate(0, nums, item, result);
        return result;
    }

private:
    void generate(int i, std::vector<int> &nums, std::vector<int> &item, std::vector<std::vector<int>> &result) {
        if (i >= nums.size()) return;

        item.push_back(nums[i]);
        result.push_back(item);

        generate(i + 1, nums, item, result);
        item.pop_back();
        generate(i + 1, nums, item, result);
    }
};

class Solution2 {
public:
    vector<vector<int>> subsets(vector<int> &nums) {
        std::vector<std::vector<int>> result;
        int all_set = 1 << nums.size();
        for (int i = 0; i < all_set; i++) {
            std::vector<int> item;
            for (int j = 0; j < i; j++) {
                if (i & (1 << j)) {
                    item.push_back(nums[j]);
                }
            }
            result.push_back(item);
        }
        return result;
    }
};

int main(int argc, char **argv) {
    std::vector<int> nums = {1, 2, 3};
    Solution solution;
    auto ret = solution.subsets(nums);
    for (const auto &i : ret) {
        std::cout << "[";
        for (const auto &j : i) {
            std::cout << j;
        }
        std::cout << "]";
    }
    std::cout << std::endl;
    Solution2 solution2;
    auto ret2 = solution2.subsets(nums);
    for (const auto &i : ret2) {
        std::cout << "[";
        for (const auto &j : i) {
            std::cout << j;
        }
        std::cout << "]";
    }
    return EXIT_SUCCESS;
}