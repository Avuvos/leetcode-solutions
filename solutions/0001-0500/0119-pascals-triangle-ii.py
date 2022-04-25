class Solution:
    def getRow(self, rowIndex: int) -> List[int]:
        
        res = [0] * (rowIndex+1)
        res[0] = 1
        
        for i in range(1, rowIndex+1): #i=1 means row number 2 
            for j in range(i, 0, -1):
                res[j] += res[j-1]
            
        return res
            
