//
// Created by mincong.he on 2021/4/5.
//

#include <vector>
#include "AlgoUtils.h"

using namespace std;

class Solution {
public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n) {
        if (n < 1 || nums2.empty()) return;
        int nums1_size = nums1.size();
        int p1 = m - 1;
        int p2 = n - 1;
        for (int i = nums1_size - 1; i >= 0; --i) {
            if (p1 < 0) {
                nums1[i] = nums2[p2--];
            } else if (p2 < 0 || nums1[p1] > nums2[p2]) {
                nums1[i] = nums1[p1--];
            } else {
                nums1[i] = nums2[p2--];
            }
        }
    }
};

int main(int argc, char **argv) {
    Solution s;
    vector<int> nums1_1{1, 2, 3, 0, 0, 0};
    vector<int> nums2_1{2, 5, 6};
    vector<int> ret_1{1, 2, 2, 3, 5, 6};
    s.merge(nums1_1, 3, nums2_1, 3);
    assertArray(nums1_1, ret_1);

    vector<int> nums1_2{1};
    vector<int> nums2_2{};
    vector<int> ret_2{1};
    s.merge(nums1_2, 1, nums2_2, 0);
    assertArray(nums1_2, ret_2);

    vector<int> nums1_3{0};
    vector<int> nums2_3{1};
    vector<int> ret_3{1};
    s.merge(nums1_3, 0, nums2_3, 1);
    assertArray(nums1_3, ret_3);

    return EXIT_SUCCESS;
}