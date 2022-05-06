class Solution:
    def mySqrt(self, x: int) -> int:
        if x == 0: return 0
        if x == 1: return 1
        
        left, right = 0, x
        while left < right:
            mid = (left + right + 1) // 2
            if int(mid**2) == x:
                return mid
            elif mid**2 > x:
                right = mid - 1
            else:
                left = mid
                
        return left
