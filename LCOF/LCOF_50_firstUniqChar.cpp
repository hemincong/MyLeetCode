//
// Created by mincong.he on 2021/7/22.
//

class Solution {
public:
    char firstUniqChar(string s) {
        vector<int> m(26, 0);
        for (int i = 0; i < s.size(); ++i) {
            m.at(s[i] - 'a')++;
        }
        for (int i = 0; i < s.size(); ++i) {
            if (m.at(s[i] - 'a') == 1) return s[i];
        }
        return ' ';
    }
};