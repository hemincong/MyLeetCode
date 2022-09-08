//
// Created by mincong.he on 2022/9/8.
//
class Solution {
public:
    vector<int> constructArray(int n, int k) {
        vector<int> ret(n, 0);
        int num = 1;
        for (int i = 0; i <= k; i += 2) {
            ret[i] = num++;
        }
        num = k + 1;
        for (int i = 1; i <= k; i += 2) {
            ret[i] = num--;
        }

        for (int i = k + 1; i < n; i++) {
            ret[i] = i + 1;
        }
        return ret;

    }
};