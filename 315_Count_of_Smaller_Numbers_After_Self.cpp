//
// Created by mincong.he on 2019/11/8.
//
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> countSmaller(vector<int> &nums) {
        std::vector<std::pair<int, int>> t;
        std::vector<int> count(nums.size(), 0);
        t.reserve(nums.size());
        int index = 0;
        for (const auto &i: nums) {
            t.emplace_back(std::make_pair(i, index++));
        }
        merge(t, count);

        return count;
    }

private:
    static void merge(vector<std::pair<int, int>> &nums,
                      vector<int> &count) {
        if (nums.size() < 2) {
            return;
        }

        auto iter = nums.begin();
        for (int i = 0; i < nums.size() / 2; i++) {
            iter++;
        }
        vector<std::pair<int, int>> left(nums.begin(), iter);
        vector<std::pair<int, int>> right(iter, nums.end());

        merge(left, count);
        merge(right, count);

        nums.clear();
        merge_and_set_count(left, right, nums, count);
    }

    static void merge_and_set_count(
            vector<std::pair<int, int>> &left,
            vector<std::pair<int, int>> &right,
            vector<std::pair<int, int>> &ret,
            vector<int> &count
    ) {
        int i = 0;
        int j = 0;

        while (i < left.size() && j < right.size()) {
            if (left[i].first <= right[j].first) {
                count[left[i].second] += j;
                ret.push_back(left[i]);
                i++;
            } else {
                ret.push_back(right[j]);
                j++;
            }
        }

        while (i < left.size()) {
            count[left[i].second] += j;
            ret.push_back(left[i]);
            i++;
        }
        while (j < right.size()) {
            ret.push_back(right[j]);
            j++;
        }
    }
};

int main(int argc, char **argv) {
    std::vector<int> nums{5, -7, 9, 1, 3, 5, -2, 1};

    Solution solution;
    auto ret = solution.countSmaller(nums);
    for (const auto &i : ret) {
        std::cout << i << " " << std::endl;;
    }

    return EXIT_SUCCESS;
}