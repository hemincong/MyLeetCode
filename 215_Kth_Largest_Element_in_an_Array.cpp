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
    std::vector<int> nums = {3, 2, 1, 5, 6, 4};
    Solution solve;
    printf("%d\n", solve.findKthLargest(nums, 2));

    std::vector<int> nums_2 = {3, 2, 1, 2, 4, 5, 5, 6};
    Solution solve2;
    printf("%d\n", solve2.findKthLargest(nums_2, 4));
    return EXIT_SUCCESS;
}