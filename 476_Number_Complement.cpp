//
// Created by mincong.he on 2021/10/21.
//

class Solution {
public:
    int findComplement(int num) {
        int temp = num;
        int c = 0;
        while (temp > 0) {
            temp >>= 1;
            c = (c << 1) + 1;
        }
        return num ^ c;
    }
};