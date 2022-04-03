class Solution:
    def maximumCandies(self, candies: List[int], k: int) -> int:
        
        def check(num):
            cnt = 0
            for c in candies:
                cnt += c // num
            return cnt >= k
            
        left = 0
        right = max(candies)
        
        while left < right:
            mid = (left + right + 1) // 2
            if check(mid):
                left = mid
            else:
                right = mid - 1
                
        return left
                
