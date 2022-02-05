//
// Created by mincong.he on 2022/2/4.
//

class Solution {
public:
    int countGoodRectangles(vector<vector<int>>& rectangles) {
        auto max = INT_MIN;
        int count = 0;
        for (const auto& r : rectangles) {
            auto min_r = min(r[0], r[1]);
            if (min_r == max) {
                count++;
            } else if (min_r > max) {
                count = 1;
                max = min_r;
            }
        }
        return count;
    }
};