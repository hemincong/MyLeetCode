//
// Created by mincong.he on 2021/2/11.
//

#include <vector>
#include "AlgoUtils.h"

using namespace std;

class KthLargest {
public:
    KthLargest(int k, vector<int> &nums) : _k(k) {
        for (auto n : nums) {
            _p.push(n);
        }
        int d = nums.size() - k;
        for (int i = 0; i < d; i++) {
            _p.pop();
        }
    }

    int add(int val) {
        if (_p.size() == _k) {
            auto top = _p.top();
            if (val > top) {
                _p.pop();
                _p.push(val);
            }
        } else {
            _p.push(val);
        }

        return _p.top();
    }

private:
    int _k;
    priority_queue<int, vector<int>, std::greater<int>> _p;
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */

int main(int argc, char **argv) {
    vector<int> test_case_1{4, 5, 8, 2};
    KthLargest kthLargest_1(3, test_case_1);
    EXPECT_EQ(kthLargest_1.add(3), 4);
    EXPECT_EQ(kthLargest_1.add(5), 5);
    EXPECT_EQ(kthLargest_1.add(10), 5);
    EXPECT_EQ(kthLargest_1.add(9), 8);
    EXPECT_EQ(kthLargest_1.add(4), 8);

    vector<int> test_case_2{};
    KthLargest kthLargest_2(1, test_case_2);
    EXPECT_EQ(kthLargest_2.add(-3), -3);
    EXPECT_EQ(kthLargest_2.add(-2), -2);
    EXPECT_EQ(kthLargest_2.add(-4), -2);
    EXPECT_EQ(kthLargest_2.add(0), 0);
    EXPECT_EQ(kthLargest_2.add(4), 4);

    return EXIT_SUCCESS;
}