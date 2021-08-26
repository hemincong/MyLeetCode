#include <vector>
#include "AlgoUtils.h"

using namespace std;

class Solution {
public:
    int numRescueBoats(vector<int> &people, int limit) {
        int n = people.size();
        std::sort(people.begin(), people.end());
        int l = 0;
        int r = n - 1;
        int ret = 0;
        while (l <= r) {
            if (people[l] + people[r] <= limit) {
                l++;
                r--;
            } else if (people[r] <= limit) {
                r--;
            } else {
                l++;
            }
            ret++;
        }
        return ret;
    }
};

int main(int argc, char **argv) {
    Solution s;
    vector<int> people_1{1, 2};
    EXPECT_EQ(s.numRescueBoats(people_1, 3), 1)

    vector<int> people_2{3, 2, 2, 1};
    EXPECT_EQ(s.numRescueBoats(people_2, 3), 3)

    vector<int> people_3{3, 5, 3, 4};
    EXPECT_EQ(s.numRescueBoats(people_3, 5), 4)

    return EXIT_SUCCESS;
}