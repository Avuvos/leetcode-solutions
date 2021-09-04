class Solution:
    def findFarmland(self, land: List[List[int]]) -> List[List[int]]:
        res = []
        n = len(land)
        m = len(land[0])
    
        for i in range(n):
            for j in range(m):
                if land[i][j] == 1:
                    topX = i
                    topY = j
                    botX = i
                    botY = j
                    
                    while (botX < n and land[botX][j] == 1): 
                        botX += 1
                    while (botY < m and land[i][botY] == 1): 
                        botY += 1
                        
                    res.append([topX, topY, botX-1, botY-1])
                    
                    for x in range(i, botX):
                        for y in range(j, botY):
                            land[x][y] = 0
                    
        return res
