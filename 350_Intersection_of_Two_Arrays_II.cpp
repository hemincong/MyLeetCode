//
// Created by mincong.he on 2020/7/13.
//
#include <vector>
#include <map>
#include "AlgoUtils.h"

using namespace std;

class Solution {
public:
    vector<int> intersect(vector<int> &nums1, vector<int> &nums2) {
        vector<int> ret;
        if (nums1.empty() || nums2.empty()) return ret;

        map<int, int> n1;
        for (const auto &n : nums1) {
            if (n1.find(n) == n1.end()) {
                n1[n] = 1;
            } else n1[n]++;
        }
        for (const auto &n : nums2) {
            if (n1.find(n) != n1.end()) {
                auto c = n1[n];
                if (c > 0) {
                    n1[n]--;
                    ret.push_back(n);
                }
            }
        }
        return ret;
    }
};

int main(int argc, char **argv) {
    Solution solution;
    vector<int> nums1_1 = {1, 2, 2, 1};
    vector<int> nums2_1 = {2, 2};
    auto ret_1 = solution.intersect(nums1_1, nums2_1);
    for (const auto &n : ret_1) {
        std::cout << n << " " << std::endl;
    }

    vector<int> nums1_2 = {4, 9, 5};
    vector<int> nums2_2 = {9, 4, 9, 8, 4};
    auto ret_2 = solution.intersect(nums1_2, nums2_2);
    for (const auto &n : ret_2) {
        std::cout << n << " " << std::endl;
    }
    return EXIT_SUCCESS;
}