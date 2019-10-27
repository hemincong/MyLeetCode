//
// Created by mincong.he on 2019/10/27.
//

#include <iostream>
#include <vector>
#include <set>

using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int> &candidates, int target) {
        std::set<std::vector<int>> result;
        std::vector<int> item;
        std::sort(candidates.begin(), candidates.end());
        _target = target;
        int sum = 0;
        generate(0, candidates, item, sum, result);
        std::vector<std::vector<int>> r(result.begin(), result.end());
        return r;
    }

private:
    void
    generate(int i, std::vector<int> &nums, std::vector<int> &item, int sum, std::set<vector<int>> &result) {
        if (i >= nums.size()) return;

        sum += nums[i];
        item.push_back(nums[i]);
        if (sum < _target) {
            generate(i + 1, nums, item, sum, result);
        } else if (sum == _target) {
            if (result.find(item) == result.end()) {
                result.insert(item);
            }
        }
        item.pop_back();
        sum -= nums[i];
        generate(i + 1, nums, item, sum, result);
    }

private:
    int _target;
};

int main(int argc, char **argv) {
    std::vector<int> nums = {10, 1, 2, 7, 6, 1, 5};
    int target = 8;
    Solution solution{};
    auto ret = solution.combinationSum2(nums, target);
    for (const auto &i : ret) {
        std::cout << "[";
        for (const auto &j : i) {
            std::cout << j;
        }
        std::cout << "]";
    }

    std::cout << std::endl;
    std::vector<int> nums_2 = {2, 5, 2, 1, 2};
    int target_2 = 5;
    auto ret_2 = solution.combinationSum2(nums_2, target_2);
    for (const auto &i : ret_2) {
        std::cout << "[";
        for (const auto &j : i) {
            std::cout << j;
        }
        std::cout << "]";
    }
    return EXIT_SUCCESS;
}