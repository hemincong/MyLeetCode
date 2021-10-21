//
// Created by mincong.he on 2021/10/21.
//

class Solution {
public:
    int peakIndexInMountainArray(vector<int> &arr) {
        int n = arr.size();

        int l = 0;
        int r = n - 1;
        while (l < r) {
            int mid = (l + r + 1) >> 1;
            if (arr[mid - 1] < arr[mid]) {
                l = mid;
            } else {
                r = mid - 1;
            }
        }
        return l;
    }
};