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
    return EXIT_SUCCESS;
}