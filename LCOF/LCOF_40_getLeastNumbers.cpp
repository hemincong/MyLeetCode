//
// Created by mincong.he on 2021/7/21.
//

// 无节操版
// 有节操的用大顶堆，懒
class Solution {
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        sort(arr.begin(), arr.end());
        arr.resize(k);
        return arr;
    }
};
