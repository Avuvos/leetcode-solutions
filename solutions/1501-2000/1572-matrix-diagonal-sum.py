class Solution:
    def diagonalSum(self, mat: List[List[int]]) -> int:
        ans = 0
        n = len(mat)
        for i in range(n):
            ans += mat[i][i]
            ans += mat[i][n - i - 1]
        if n & 1:
            ans -= mat[n // 2][n // 2];
        return ans
