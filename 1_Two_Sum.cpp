//
// Created by mincong.he on 2019/9/18.
//

#include <vector>
#include <map>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int> &nums, int target) {
        map<int, int> m;
        for (int i = 0; i < nums.size(); ++i) {
            m[nums.at(i)] = i;
        }

        for (int i = 0; i < nums.size(); ++i) {
            auto n = nums.at(i);
            auto remain = target - n;
            if (m.find(remain) != m.end()) {
                auto remain_index = m[remain];
                if (i != remain_index) {
                    auto ret = vector<int>();
                    ret.emplace_back(i);
                    ret.emplace_back(remain_index);
                    return ret;
                }
            }
        }
        return vector<int>();
    }
};

int main(int argc, char **argv) {
    Solution solve;
    vector<int> nums_1;
    nums_1.emplace_back(2);
    nums_1.emplace_back(7);
    nums_1.emplace_back(11);
    nums_1.emplace_back(15);
    auto ret = solve.twoSum(nums_1, 9);
    for (auto &n: ret) {
        std::cout << n << std::endl;
    }

    vector<int> nums_2;
    nums_2.emplace_back(3);
    nums_2.emplace_back(3);
    nums_2.emplace_back(15);
    auto ret_2 = solve.twoSum(nums_1, 2);
    for (auto &n: ret_2) {
        std::cout << n << std::endl;
    }

    return EXIT_SUCCESS;
}
