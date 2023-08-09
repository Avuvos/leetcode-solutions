class Solution:
    def minimizeMax(self, nums: List[int], p: int) -> int:
        nums.sort()
        INF = 10**12
        
        
        def ok(x):
            res = i = 0
            while i < len(nums):
                if i + 1 < len(nums) and nums[i + 1] - nums[i] <= x:
                    res += 1
                    i += 1
                i += 1
            return res >= p
        
        
        left = 0
        right = ans = INF
        
        while left <= right:
            mid = left + (right - left)//2
            if ok(mid):
                ans = mid
                right = mid - 1
            else:
                left = mid + 1
        
        return ans
