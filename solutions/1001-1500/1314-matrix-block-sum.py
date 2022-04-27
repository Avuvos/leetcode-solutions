class Solution:
    def matrixBlockSum(self, mat: List[List[int]], k: int) -> List[List[int]]:
        n, m = len(mat), len(mat[0])
        ans = [[0 for _ in range(m)] for _ in range(n)]
        prefixSum = [[0 for _ in range(m + 1)] for _ in range(n + 1)]

        for i in range(1, n + 1):
            for j in range(1, m + 1):
                prefixSum[i][j] = mat[i - 1][j - 1] + prefixSum[i - 1][j] + prefixSum[i][j - 1] - prefixSum[i - 1][j - 1]

        for i in range(n):
            for j in range(m):
                r1, r2 = max(0, i - k) + 1, min(n - 1, i + k) + 1
                c1, c2 = max(0, j - k) + 1, min(m - 1, j + k) + 1
                ans[i][j] = prefixSum[r2][c2] - prefixSum[r2][c1 - 1] \
                            - prefixSum[r1 - 1][c2] + prefixSum[r1 - 1][c1 - 1]
        return ans
