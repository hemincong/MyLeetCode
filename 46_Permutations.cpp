//
// Created by mincong.he on 2021/1/5.
//

#include "AlgoUtils.h"
#include <vector>
#include <set>

using namespace std;

class Solution {
public:
    vector<vector<int>> permute(vector<int> &nums) {
        std::vector<int> item;
        std::vector<std::vector<int>> ret;
        std::set<int> visited;
        generate(nums, visited, item, ret);
        return ret;
    }

private:
    void generate(const std::vector<int> &nums, std::set<int> visited, std::vector<int> &item,
                  std::vector<std::vector<int>> &result) {
        if (item.size() == nums.size()) {
            result.push_back(item);
            return;
        };

        for (int j = 0; j < nums.size(); ++j) {
            if (visited.find(nums[j]) == visited.end()) {
                visited.insert(nums[j]);
                item.push_back(nums[j]);
                generate(nums, visited, item, result);
                item.pop_back();
                visited.erase(nums[j]);
            }
        }
    }
};

int main(int argc, char **argv) {
    Solution s;
    vector<int> test_case_1{1, 2, 3};
    printMatrix(s.permute(test_case_1));
    return EXIT_SUCCESS;
}