//
// Created by mincong.he on 2022/8/29.
//
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        vector<char> char_map(128, '\0');
        vector<char> r_char_map(127, '\0');

        int n = s.size();
        for (int i = 0; i < n; ++i) {
            auto s_c = s[i];
            auto t_c = t[i];

            if (char_map[s_c] != '\0' && char_map[s_c] != t_c) {
                return false;
            }
            if (r_char_map[t_c] != '\0' && r_char_map[t_c] != s_c) {
                return false;
            }

            char_map[s_c] = t_c;
            r_char_map[t_c] = s_c;
        }
        return true;
    }
};