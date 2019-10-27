//
// Created by mincong.he on 2019/10/27.
//

#include <vector>
#include <set>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int> &nums) {
        std::vector<std::vector<int>> result;
        std::vector<int> item;
        std::sort(nums.begin(), nums.end());
        result.push_back(item);
        generate(0, nums, item, result);
        std::set<std::vector<int>> r_s(result.begin(), result.end());
        std::vector<std::vector<int>> r(r_s.begin(), r_s.end());
        return r;
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
    std::vector<int> nums = {4, 4, 4, 1, 4};
    Solution solution;
    auto ret = solution.subsetsWithDup(nums);
    for (const auto &i : ret) {
        std::cout << "[";
        for (const auto &j : i) {
            std::cout << j;
        }
        std::cout << "]";
    }
    return EXIT_SUCCESS;
}