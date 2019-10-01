//
// Created by mincong.he on 2019/10/2.
//

#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int findKthLargest(vector<int> &nums, int k) {
        std::priority_queue<int, std::vector<int>, std::greater<>> Q;
        for (const auto &i : nums) {
            if (Q.size() < k) {
                Q.push(i);
            } else if (Q.top() < i) {
                Q.pop();
                Q.push(i);
            }
        }

        return Q.top();
    }
};

int main(int argc, char **argv) {
    std::vector<int> nums;
    nums.push_back(3);
    nums.push_back(2);
    nums.push_back(1);
    nums.push_back(5);
    nums.push_back(6);
    nums.push_back(4);
    Solution solve;
    printf("%d\n", solve.findKthLargest(nums, 2));

    nums.clear();

    nums.push_back(3);
    nums.push_back(2);
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(4);
    nums.push_back(5);
    nums.push_back(5);
    nums.push_back(6);
    Solution solve2;
    printf("%d\n", solve2.findKthLargest(nums, 4));
    return EXIT_SUCCESS;
}