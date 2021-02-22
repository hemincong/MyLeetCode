from typing import List


# class Solution:
#     def isToeplitzMatrix(self, matrix: List[List[int]]) -> bool:
#         n = len(matrix)
#         m = len(matrix[0])
#         d = m - n + 1
#         if d < 1:
#             d = 1
#
#         for i in range(0, m):
#             tmp = matrix[0][i]
#             c = i
#             r = 0
#             while c < m and r < n:
#                 if matrix[r][c] != tmp:
#                     return False
#                 c += 1
#                 r += 1
#
#         for i in range(0, n):
#             tmp = matrix[i][0]
#             c = 0
#             r = i
#             while c < m and r < n:
#                 if matrix[r][c] != tmp:
#                     return False
#                 c += 1
#                 r += 1
#         return True

class Solution:
    def isToeplitzMatrix(self, matrix: List[List[int]]) -> bool:
        n = len(matrix)
        m = len(matrix[0])
        for i in range(1, n):
            for j in range(1, m):
                if matrix[i][j] != matrix[i - 1][j - 1]:
                    return False

        return True


if __name__ == "__main__":
    s = Solution()
    ret_1 = s.isToeplitzMatrix([[1, 2, 3, 4], [5, 1, 2, 3], [9, 5, 1, 2]])
    assert ret_1
    ret_2 = s.isToeplitzMatrix([[1, 2], [2, 2]])
    assert (not ret_2)
    ret_3 = s.isToeplitzMatrix([[97, 97], [80, 6], [10, 79]])
    assert (not ret_3)
    ret_4 = s.isToeplitzMatrix(
        [[36, 59, 71, 15, 26, 82, 87], [56, 36, 59, 71, 15, 26, 82], [15, 0, 36, 59, 71, 15, 26]])
    assert (not ret_4)
