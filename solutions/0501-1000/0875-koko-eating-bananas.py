class Solution:
    def minEatingSpeed(self, piles: List[int], h: int) -> int:
        
        
        def good(k):
            time = 0
            for p in piles:
                if p <= k:
                    time += 1
                else:
                    if p % k != 0:
                        time += 1
                    time += p//k
            return time <= h
            
        
        left, right = 1, max(piles)
        while left < right:
            mid = (left + right) // 2
            if good(mid):
                right = mid
            else:
                left = mid + 1
        return left
        
