//
// Created by mincong.he on 2022/4/10.
//

class Solution {
public:
    int countPrimeSetBits(int left, int right) {
        int ret = 0;
        for (int i = left; i <= right; ++i) {
            int bit_count = 0;
            int n = i;
            while (n > 0) {
                if ((n & 0b1) == 1) bit_count++;
                n >>= 1;
            }
            if (prime.find(bit_count) != prime.end()) ret++;
        }
        return ret;
    }

private:
    const unordered_set<int> prime{2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31};
};