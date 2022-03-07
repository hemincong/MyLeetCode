//
// Created by mincong.he on 2022/3/3.
//

class Solution {
public:
    int addDigits(int num) {
        if (num > 9) {
            num = num % 9;
            if (num == 0) {
                return 9;
            }
        }
        return num;
    }
};