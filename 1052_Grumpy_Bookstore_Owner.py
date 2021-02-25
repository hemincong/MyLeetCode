from typing import List


class Solution:
    def maxSatisfied(self, customers: List[int], grumpy: List[int], X: int) -> int:
        total = 0
        for i in range(len(customers)):
            if grumpy[i] == 0:
                total += customers[i]

        diff = 0
        for i in range(X):
            if grumpy[i] == 1:
                diff += customers[i]

        max_diff = diff
        for i in range(X, len(grumpy)):
            if grumpy[i - X] == 1:
                diff -= customers[i - X]
            if grumpy[i] == 1:
                diff += customers[i]
            max_diff = diff if diff > max_diff else max_diff
        return max_diff + total


if __name__ == '__main__':
    s = Solution()
    ret = s.maxSatisfied(customers=[1, 0, 1, 2, 1, 1, 7, 5], grumpy=[0, 1, 0, 1, 0, 1, 0, 1], X=3)
    print(ret)
    assert (ret == 16)

    ret = s.maxSatisfied(customers=[1], grumpy=[0], X=1)
    print(ret)
    assert (ret == 1)

    ret = s.maxSatisfied([4, 10, 10], [1, 1, 0], 2)
    print(ret)
    assert (ret == 24)
