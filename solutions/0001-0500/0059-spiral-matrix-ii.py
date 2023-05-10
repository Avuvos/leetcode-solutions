class Solution:
    def generateMatrix(self, n: int) -> List[List[int]]:
        left = top = 0
        right = bot = n
        ans = [[0 for _ in range(n)] for _ in range(n)]
        x = 1
        while left < right and top < bot:
            for i in range(left, right):
                ans[top][i] = x
                x += 1
            top += 1
            for i in range(top, bot):
                ans[i][right - 1] = x
                x += 1
            right -= 1
            
            if left >= right or top >= bot:
                break
                
            for i in range(right - 1, left - 1, -1):
                ans[bot - 1][i] = x
                x += 1
            bot -= 1
            for i in range(bot - 1, top - 1, -1):
                ans[i][left] = x
                x += 1
            left += 1
            
        return ans    
