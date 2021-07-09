//
// Created by mincong.he on 2021/5/16.
//

#include <vector>
#include "AlgoUtils.h"

using namespace std;

struct Trie {
    // 左子树指向表示 0 的子节点
    Trie *left = nullptr;
    // 右子树指向表示 1 的子节点
    Trie *right = nullptr;

    Trie() {}
};

class Solution {
private:
    // 字典树的根节点
    Trie *root = new Trie();
    // 最高位的二进制位编号为 30
    static constexpr int HIGH_BIT = 30;

public:
    void add(int num) {
        Trie *cur = root;
        for (int k = HIGH_BIT; k >= 0; --k) {
            int bit = (num >> k) & 1;
            if (bit == 0) {
                if (!cur->left) {
                    cur->left = new Trie();
                }
                cur = cur->left;
            } else {
                if (!cur->right) {
                    cur->right = new Trie();
                }
                cur = cur->right;
            }
        }
    }

    int check(int num) {
        Trie *cur = root;
        int x = 0;
        for (int k = HIGH_BIT; k >= 0; --k) {
            int bit = (num >> k) & 1;
            if (bit == 0) {
                // a_i 的第 k 个二进制位为 0，应当往表示 1 的子节点 right 走
                if (cur->right) {
                    cur = cur->right;
                    x = x * 2 + 1;
                } else {
                    cur = cur->left;
                    x = x * 2;
                }
            } else {
                // a_i 的第 k 个二进制位为 1，应当往表示 0 的子节点 left 走
                if (cur->left) {
                    cur = cur->left;
                    x = x * 2 + 1;
                } else {
                    cur = cur->right;
                    x = x * 2;
                }
            }
        }
        return x;
    }

    int findMaximumXOR(vector<int> &nums) {
        int n = nums.size();
        int x = 0;
        for (int i = 1; i < n; ++i) {
            // 将 nums[i-1] 放入字典树，此时 nums[0 .. i-1] 都在字典树中
            add(nums[i - 1]);
            // 将 nums[i] 看作 ai，找出最大的 x 更新答案
            x = max(x, check(nums[i]));
        }
        return x;
    }
};

int main(int argc, char **argv) {
    Solution s;
    auto test_case_1 = vector<int>{3, 10, 5, 25, 2, 8};
    EXPECT_EQ(s.findMaximumXOR(test_case_1), 28);

    auto test_case_2 = vector<int>{0};
    EXPECT_EQ(s.findMaximumXOR(test_case_2), 0);

    auto test_case_3 = vector<int>{2, 4};
    EXPECT_EQ(s.findMaximumXOR(test_case_3), 6);

    auto test_case_4 = vector<int>{8, 10, 2};
    EXPECT_EQ(s.findMaximumXOR(test_case_4), 10);

    auto test_case_5 = vector<int>{14, 70, 53, 83, 49, 91, 36, 80, 92, 51, 66, 70};
    EXPECT_EQ(s.findMaximumXOR(test_case_5), 127);

    return EXIT_SUCCESS;
}