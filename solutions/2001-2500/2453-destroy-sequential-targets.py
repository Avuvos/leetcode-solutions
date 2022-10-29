class Solution:
    def destroyTargets(self, nums: List[int], space: int) -> int:
        nums.sort()
        rem = [x % space for x in nums]
        d = {}
        for r in rem:
            d[r] = d.get(r, 0) + 1
        
        best = max(d.values())
        
        res = float('inf')
        for x, r in zip(nums, rem):
            if d[r] == best:
                res = min(res, x)
                
        if res != float('inf'): return res
        return min(nums)
            
        
        
