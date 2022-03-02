//
// Created by mincong.he on 2022/2/20.
//

class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        auto iter = bits.rbegin();
        iter++;
        int one_count = 1;
        while (iter!=bits.rend()) {
            if (*iter == 1) {
                one_count++;
                iter++;
            } else {
                break;
            }
        }
        return (one_count & 1) != 0;
    }
};