class Solution:
    def spiralOrder(self, matrix: List[List[int]]) -> List[int]:
        n, m = len(matrix), len(matrix[0])
        left = top = 0
        right = m
        bot = n
        ans = []
        
        while left < right and top < bot:
            for i in range(left, right):
                ans.append(matrix[left][i])
            top += 1
            for i in range(top, bot):
                ans.append(matrix[i][right - 1]);
            right -= 1
            
            if left >= right or top >= bot:
                break
                
            for i in range(right - 1, left - 1, -1):
                ans.append(matrix[bot - 1][i])
            bot -= 1
            for i in range(bot - 1, top - 1, -1):
                ans.append(matrix[i][left])
            left += 1
            
        return ans    
            
            
        
