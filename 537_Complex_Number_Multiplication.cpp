//
// Created by mincong.he on 2022/2/27.
//

class Solution {
public:
    string complexNumberMultiply(string num1, string num2) {
        int n1, ni1, n2, ni2;
        sscanf(num1.c_str(), "%d+%di", &n1, &ni1);
        sscanf(num2.c_str(), "%d+%di", &n2, &ni2);

        auto ret_n = n1 * n2 - ni1 * ni2;
        auto ret_i = n1 * ni2 + ni1 * n2;
        char buff[16] = {'\0'};
        sprintf(buff, "%d+%di", ret_n, ret_i);
        return {buff};
    }
};