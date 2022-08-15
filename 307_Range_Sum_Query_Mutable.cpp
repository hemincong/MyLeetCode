//
// Created by mincong.he on 2021/1/2.
//

#include "AlgoUtils.h"
#include <vector>
#include <string>

using namespace std;


class NumArray {
public:
    NumArray(vector<int> &nums) :
            _segment_tree(nums.size() * sizeof(int), 0),
            _n(nums.size()) {
        _build(0, 0, _n - 1, nums);
    }

    void update(int i, int val) {
        _change(i, val, 0, 0, _n - 1);
    }

    int sumRange(int left, int right) {
        return _range(left, right, 0, 0, _n - 1);
    }

private:
    void _build(int node, int s, int e, vector<int> &nums) {
        if (s == e) {
            _segment_tree[node] = nums[s];
            return;
        }
        int m = s + ((e - s) / 2) ;
        _build(node * 2 + 1, s, m, nums);
        _build(node * 2 + 2, m + 1, e, nums);
        _segment_tree[node] = _segment_tree[node * 2 + 1] + _segment_tree[node * 2 + 2];
    }

    void _change(int index, int val, int node, int s, int e) {
        if (s == e) {
            _segment_tree[node] = val;
            return;
        }

        int m = s + ((e - s) / 2) ;
        if (index <= m) {
            _change(index, val, node * 2 + 1, s, m);
        } else {
            _change(index, val, node * 2 + 2, m + 1, e);
        }
        _segment_tree[node] = _segment_tree[node * 2 + 1] + _segment_tree[node * 2 + 2];
    }

    int _range(int left, int right, int node, int s, int e) {
        if (left == s && right == e) {
            return _segment_tree[node];
        }

        int m = s + ((e - s) / 2) ;
        if (right <= m) {
            return _range(left, right, node * 2 + 1, s, m);
        } else if (left > m) {
            return _range(left, right, node * 2 + 2, m + 1, e);
        } else {
            return _range(left, m, node * 2 + 1, s, m) + _range(m+ 1, right, node * 2 + 2, m + 1, e);
        }
    }


    std::vector<int> _segment_tree;
    int _n;
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(i,val);
 * int param_2 = obj->sumRange(i,j);
 */

int main(int argc, char **argv) {
    vector<int> test_case_1{1, 3, 5};
    NumArray numArray_1(test_case_1);
    EXPECT_EQ(numArray_1.sumRange(0, 2), 9);
    numArray_1.update(1, 2);
    EXPECT_EQ(numArray_1.sumRange(0, 2), 8);

    return EXIT_SUCCESS;
}