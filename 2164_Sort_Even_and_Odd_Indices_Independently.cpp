//
// Created by mincong.he on 2022/2/9.
//

class Solution {
public:
    vector<int> sortEvenOdd(vector<int> &nums) {
        vector<int> even_vec;
        vector<int> odd_vec;
        for (int i = 0; i < nums.size(); ++i) {
            if ((i & 1) == 0) {
                // 偶数
                even_vec.push_back(nums[i]);
            } else {
                odd_vec.push_back(nums[i]);
            }
        }
        sort(even_vec.begin(), even_vec.end());
        sort(odd_vec.rbegin(), odd_vec.rend());
        vector<int> ret;
        auto even_iter = even_vec.begin();
        auto odd_iter = odd_vec.begin();

        while (even_iter != even_vec.end() && odd_iter != odd_vec.end()) {
            ret.push_back(*even_iter);
            ret.push_back(*odd_iter);
            even_iter++;
            odd_iter++;
        }
        if (even_iter != even_vec.end()) ret.push_back(*even_iter);
        if (odd_iter != odd_vec.end()) ret.push_back(*odd_iter);

        return ret;
    }
};