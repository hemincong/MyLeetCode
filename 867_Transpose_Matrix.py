from typing import List


class Solution:
    def transpose(self, matrix: List[List[int]]) -> List[List[int]]:
        n = len(matrix)
        m = len(matrix[0])

        tmp = [[0 for x in range(n)] for y in range(m)]
        for i in range(n):
            for j in range(m):
                tmp[j][i] = matrix[i][j]

        return tmp