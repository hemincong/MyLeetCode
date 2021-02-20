from typing import List


class Solution:
    def findShortestSubArray(self, nums: List[int]) -> int:
        num_count = {}
        last_pos = {}
        first_pos = {}
        for i in range(len(nums)):
            num = nums[i]
            if num in num_count:
                num_count[num] += 1
            else:
                num_count[num] = 1

            if not num in first_pos:
                first_pos[num] = i

            last_pos[num] = i

        sorted_nums = sorted(num_count.items(), key=lambda x: x[1], reverse=True)
        max_degree = sorted_nums[0][1]
        subarray_min_len = len(nums)
        for n, d in sorted_nums:
            if not d == max_degree:
                break
            subarray_len = last_pos[n] - first_pos[n] + 1
            if subarray_min_len > subarray_len:
                subarray_min_len = subarray_len

        return subarray_min_len


if __name__ == "__main__":
    s = Solution()
    ret_1 = s.findShortestSubArray([1, 2, 2, 3, 1])
    print(ret_1)
    assert (ret_1 == 2)

    ret_2 = s.findShortestSubArray([1, 2, 2, 3, 1, 4, 2])
    print(ret_2)
    assert (ret_2 == 6)
