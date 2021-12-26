class Solution:
    def executeInstructions(self, n: int, startPos: List[int], s: str) -> List[int]:
        
        memo = {}
        
        def dfs(i, j, idx):
            if idx >= len(s):
                return 0
            
            direction = s[idx]
            if (i, j, idx, direction) in memo:
                return memo[(i, j, idx, direction)]
            
            path = 0
            if direction == "R" and j + 1 <= n - 1:
                path = 1 + dfs(i, j + 1, idx + 1)
                
            elif direction == "L" and j - 1 >= 0:
                path = 1 + dfs(i, j - 1, idx + 1)
                
            elif direction == "U" and i - 1 >= 0:
                path = 1 + dfs(i - 1, j, idx + 1)
                
            elif direction == "D" and i + 1 <= n - 1:
                path = 1 + dfs(i + 1, j, idx + 1)
                
            memo[(i, j, idx, direction)] = path
            return memo[(i, j, idx, direction)]
        
        res = []
        for i in range(len(s)):
            res.append(dfs(startPos[0], startPos[1], i))
            
        return res
            
            
