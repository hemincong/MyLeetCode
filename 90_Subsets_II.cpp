//
// Created by mincong.he on 2019/10/27.
//

#include <vector>
#include <set>
#include "AlgoUtils.h"

using namespace std;

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int> &nums) {
        std::vector<std::vector<int>> result;
        std::vector<int> item;
        std::sort(nums.begin(), nums.end());
        result.push_back(item);
        generator(nums, 0, item, result);
        std::set<std::vector<int>> r_s(result.begin(), result.end());
        std::vector<std::vector<int>> r(r_s.begin(), r_s.end());
        return r;
    }

private:
    void generator(const vector<int> &nums, int index, vector<int> &item, vector<vector<int>> &ret) {
        if (index >= nums.size()) return;

        item.push_back(nums[index]);
        ret.push_back(item);

        generator(nums, index + 1, item, ret);
        item.pop_back();
        generator(nums, index + 1, item, ret);
    }
};

int main(int argc, char **argv) {
    Solution s;
    std::vector<int> test_case_1{4, 4, 4, 1, 4};
    printMatrix(s.subsetsWithDup(test_case_1));

    std::vector<int> test_case_2{1, 2, 2};
    printMatrix(s.subsetsWithDup(test_case_2));

    std::vector<int> test_case_3{0};
    printMatrix(s.subsetsWithDup(test_case_3));
    return EXIT_SUCCESS;
}