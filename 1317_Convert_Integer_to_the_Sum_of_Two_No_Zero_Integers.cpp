//
// Created by mincong.he on 2022/2/11.
//

class Solution {
public:
    vector<int> getNoZeroIntegers(int n) {
        vector<int> ans;
        for (int i = 1; i <= n / 2; ++i) {
            auto str1 = to_string(i);
            auto str2 = to_string(n - i);
            if (str1.find('0') == str1.npos && str2.find('0') == str2.npos) {
                ans.push_back(i);
                ans.push_back(n - i);
                return ans;
            }
        }
        return ans;
    }
};