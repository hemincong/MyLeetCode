from typing import List

from sortedcontainers import SortedList


class Solution:
    def longestSubarray(self, nums: List[int], limit: int) -> int:
        s = SortedList()
        n = len(nums)

        j = 0
        longest = 0
        for i in range(0, n):
            s.add(nums[i])
            while s[-1] - s[0] > limit:
                s.remove(nums[j])
                j += 1

            tmp = i - j + 1
            if tmp > longest:
                longest = tmp
        return longest


if __name__ == "__main__":
    s = Solution()
    ret_1 = s.longestSubarray([8, 2, 4, 7], 4)
    print(ret_1)
    assert (ret_1 == 2)

    ret_2 = s.longestSubarray([10, 1, 2, 4, 7, 2], 5)
    print(ret_2)
    assert (ret_2 == 4)

    ret_3 = s.longestSubarray([4, 2, 2, 2, 4, 4, 2, 2], 0)
    print(ret_3)
    assert (ret_3 == 3)
