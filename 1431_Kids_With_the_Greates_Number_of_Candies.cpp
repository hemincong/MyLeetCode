//
// Created by mincong.he on 2020/6/1.
//

#include <vector>

using namespace std;

class Solution {
public:
    vector<bool> kidsWithCandies(vector<int> &candies, int extraCandies) {
        vector<bool> ret;
        int max = 0;
        for (const int c : candies) {
            if (c > max) {
                max = c;
            }
        }
        ret.reserve(candies.size());
        for (const int c : candies) {
            ret.push_back(c + extraCandies >= max);
        }
        return ret;
    }
};

int main(int argc, char **argv) {
    Solution solution;
    std::vector<int> c_1{2, 3, 5, 1, 3};
    auto ret_1 = solution.kidsWithCandies(c_1, 3);
    assert(ret_1[0] && ret_1[1] && ret_1[2] && !ret_1[3] && ret_1[4]);

    std::vector<int> c_2{4, 2, 1, 1, 2};
    auto ret_2 = solution.kidsWithCandies(c_2, 1);
    assert(ret_2[0] && !ret_2[1] && !ret_2[2] && !ret_2[3] && !ret_2[4]);

    std::vector<int> c_3{12, 1, 12};
    auto ret_3 = solution.kidsWithCandies(c_3, 10);
    assert(ret_3[0] && !ret_3[1] && ret_3[2]);
}