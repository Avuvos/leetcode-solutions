class Solution:
    def calculateMinimumHP(self, dungeon: List[List[int]]) -> int:
        n = len(dungeon)
        m = len(dungeon[0])
        memo = {}
        
        def dfs(i, j):
            if i == n - 1 and j == m - 1:
                if dungeon[i][j] >= 0:
                    return 1
                else:
                    return -1 * dungeon[i][j] + 1
            if (i, j) in memo:
                return memo[(i, j)]
            
            res = float('inf')
            if i + 1 < n:
                down = dfs(i + 1, j) 
                if dungeon[i][j] >= down:
                    res = min(res, 1)
                else:
                    res = min(res, down - dungeon[i][j])
            if j + 1 < m:
                right = dfs(i, j + 1)
                if dungeon[i][j] >= right:
                    res = min(res, 1)
                else:
                    res = min(res, right - dungeon[i][j])
            memo[(i, j)] = res
            return res
        
        return dfs(0, 0)
