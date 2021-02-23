from typing import List


class Solution(object):
    def flipAndInvertImage(self, A):
        n = len(A)
        m = len(A[0])
        tmp = [[0 for x in range(n)] for y in range(m)]  

        for i in range(n):
            for j in range(m):
                tmp[i][m - j - 1] = 1 if A[i][j] == 0 else 0
        return tmp



if __name__ == '__main__':
    s = Solution()
    ret = s.flipAndInvertImage([[1,1,0],[1,0,1],[0,0,0]])
    print(ret)
    assert(ret == [[1,0,0],[0,1,0],[1,1,1]])

    ret = s.flipAndInvertImage([[1,1,0,0],[1,0,0,1],[0,1,1,1],[1,0,1,0]])
    print(ret)
    assert(ret == [[1,1,0,0],[0,1,1,0],[0,0,0,1],[1,0,1,0]])
