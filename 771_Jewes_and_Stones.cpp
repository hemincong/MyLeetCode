//
// Created by mincong.he on 2019/10/27.
//

class Solution {
public:
    int numJewelsInStones(string J, string S) {
        int count = 0;
        for (const auto &i : S) {
            if (J.find(i) != J.npos) {
                count++;
            }
        }
        return count;
    }
};