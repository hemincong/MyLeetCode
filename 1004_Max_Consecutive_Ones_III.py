from typing import List


class Solution:
    def longestOnes(self, A: List[int], K: int) -> int:
        n = len(A)

        if n == 0:
            return 0

        zero_count = 0
        max_len = 0
        curr_len = 0
        j = 0

        for i in range(0, n):
            curr_len += 1
            if A[i] == 0:
                zero_count += 1

            while zero_count > K and j <= i:
                if A[j] == 0:
                    zero_count -= 1
                curr_len -= 1
                j += 1

            if curr_len > max_len:
                max_len = curr_len

        return max_len


if __name__ == "__main__":
    s = Solution()
    ret_1 = s.longestOnes([1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0], 2)
    print(ret_1)
    assert (ret_1 == 6)

    ret_2 = s.longestOnes([0, 0, 1, 1, 0, 0, 1, 1, 1, 0, 1, 1, 0, 0, 0, 1, 1, 1, 1], 3)
    print(ret_2)
    assert (ret_2 == 10)

    ret_3 = s.longestOnes([0, 0, 0, 0], 0)
    print(ret_3)
    assert (ret_3 == 0)
