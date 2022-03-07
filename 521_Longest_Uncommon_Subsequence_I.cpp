//
// Created by mincong.he on 2022/3/6.
//

class Solution {
public:
    int findLUSlength(string a, string b) {
        if (a == b) return -1;
        auto a_len = a.size();
        auto b_len = b.size();
        return a_len > b_len ? a_len : b_len;
    }
};