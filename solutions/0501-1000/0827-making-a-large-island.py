class Solution:
    def largestIsland(self, grid: List[List[int]]) -> int:
        
        def dfs(grid, i, j, ide): #dfs to find the area of the curr island
            if (i>=len(grid) or j>=len(grid) or i<0 or j<0 or grid[i][j] != 1):
                return 0
            grid[i][j] = ide #set id of each island
            return 1 + dfs(grid, i+1, j, ide) + dfs(grid, i-1, j, ide) + dfs(grid, i, j+1, ide) + dfs(grid, i, j-1, ide)

            
        islands = {} #key is the ID of the island and value is the area
        islands[2] = 0
        islands[0] = 0
        grid_id = 2
        n = len(grid)
        for i in range(n):
            for j in range(n):
                if grid[i][j] == 1:
                    size = dfs(grid, i, j, grid_id)
                    islands[grid_id] = size #gets all the current islands and their area
                    grid_id += 1         
        res = islands[2]
        for i in range(n):
            for j in range(n):
                if grid[i][j] == 0:
                    s = set() #to avoid repetitions
                    if i > 0:
                        s.add(grid[i-1][j])
                    if i < n-1:
                        s.add(grid[i+1][j])
                    if j > 0:
                        s.add(grid[i][j-1])
                    if j < n-1:
                        s.add(grid[i][j+1])
                        
                    curr_area = 1 #count the island that im on (change this 0 to 1)
                    for ide in s: 
                        curr_area += islands[ide] #add the neighbors islands 
                    res = max(res, curr_area) #potentially update the maximum
        return res
                    
                    
                    
        
                    
                    
                    
                    
