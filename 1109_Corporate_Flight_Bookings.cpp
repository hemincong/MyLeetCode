#include <vector>
#include "AlgoUtils.h"

using namespace std;

class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>> &bookings, int n) {
        vector<int> nums(n, 0);
        for (auto &booking: bookings) {
            auto start = booking[0];
            auto end = booking[1];
            auto num = booking[2];
            nums[start - 1] += num;
            if (end < n) nums[end] -= num;
        }
        for (int i = 1; i < n; ++i) {
            nums[i] += nums[i - 1];
        }
        return nums;
    }
};

int main(int argc, char **argv) {
    Solution s;
    vector<vector<int>> bookings_1{{1, 2, 10},
                                   {2, 3, 20},
                                   {2, 5, 25}};
    vector<int> ret_1{10, 55, 45, 25, 25};
    assertArray(s.corpFlightBookings(bookings_1, 5), ret_1);

    vector<vector<int>> bookings_2{{1, 2, 10},
                                   {2, 2, 15}};
    vector<int> ret_2{10, 25};
    assertArray(s.corpFlightBookings(bookings_2, 2), ret_2);

    return EXIT_SUCCESS;
}