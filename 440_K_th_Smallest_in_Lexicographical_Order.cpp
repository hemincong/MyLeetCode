#include <vector>
#include "AlgoUtils.h"

using namespace std;

class Solution {
public:
    int findKthNumber(int n, int k) {
        int prefix = 1;
        long p = 1;
        while (p < k) {
            long count = _get_count(prefix, n);
            // 超过了上限，说明在这个范围内，在下面细找
            // 试
            if (p + count > k) {
                // 前缀虽然乘以10, 说明是往下找，位数越多越往下
                prefix *= 10;
                // 往下找一位，位置也是移了1位
                p++;
            } else {
                // 往右找
                prefix++;
                // 加上这部分的差别
                p += count;
            }
        }
        // 刚好等于，prefix就是位置
        return prefix;
    }

private:
    long _get_count(long prefix, long n) {
        long cur = prefix;
        long next = cur + 1;
        long count = 0;
        while (cur <= n) {
            // next 会超过n，则只处理剩余位数
            count += (min(next, n + 1) - cur);
            // 这里隐含了一个操作，因为不知道位数，只能扩张位数来尝试
            // 原来有1加10，再加100，诸如此类
            cur *= 10;
            next *= 10;
        }
        return count;
    }
};

int main(int argc, char **argv) {
    Solution s;
    EXPECT_EQ(s.findKthNumber(13, 2), 10)
    EXPECT_EQ(s.findKthNumber(1, 1), 1)
    return EXIT_SUCCESS;
}