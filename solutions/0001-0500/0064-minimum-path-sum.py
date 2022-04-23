class Solution:
    def minPathSum(self, grid: List[List[int]]) -> int:
        
        @cache
        def dfs(i, j):
            if i > len(grid) - 1 or j > len(grid[0]) - 1:
                return float('inf')
            if i == len(grid) - 1 and j == len(grid[0]) - 1:
                return grid[i][j]
            
            right = grid[i][j] + dfs(i, j+1)
            down = grid[i][j] + dfs(i+1, j)
            
            return min(right, down)
            
            
        return dfs(0, 0)
