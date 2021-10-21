//
// Created by mincong.he on 2021/10/21.
//

class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
        int n = digits.size();
        int mod = 0;
        digits[n - 1]++;
        for (int i = n - 1; i >= 0; --i) {

            auto temp_m = mod;
            mod = (digits[i] + temp_m) / 10;
            digits[i] = (digits[i] + temp_m) % 10;

        }
        if (mod != 0) {
            digits.insert(digits.begin(), mod);
        }
        return digits;
    }
};