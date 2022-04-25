class Solution:
    def maximalSquare(self, matrix: List[List[str]]) -> int:
        n, m = len(matrix), len(matrix[0])
        dp = [[0 for _ in range(m)] for _ in range(n)]    
        #dp[i][j] - largest square bot left corner is (i, j)
        
        res = 0
        
        for i in range(n):
            for j in range(m):
                if matrix[i][j] == '1':
                    dp[i][j] = 1
                    res = 1
                
        for i in range(1, n):
            for j in range(1, m):
                if matrix[i][j] == '1':
                    dp[i][j] = 1 + min(dp[i-1][j], dp[i][j-1], dp[i-1][j-1])
                    res = max(res, dp[i][j])
                        
        return res**2
                    
                    
        
    
