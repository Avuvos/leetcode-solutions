class Solution:
    def minFallingPathSum(self, matrix: List[List[int]]) -> int:
        n = len(matrix)
        for i in range(n-1, 0, -1):
            for j in range(0, n):
                if j == 0:
                    matrix[i-1][j] += min(matrix[i][j], matrix[i][j+1])
                elif j==n-1:
                    matrix[i-1][j] += min(matrix[i][j], matrix[i][j-1])
                else:
                    matrix[i-1][j] += min(matrix[i][j],
                                          matrix[i][j-1],
                                          matrix[i][j+1])
        return min(matrix[0])
            
