class Solution:
    def minCapability(self, nums: List[int], k: int) -> int:
        mx = max(nums)
        mn = min(nums)
        
        left = mn
        right = mx
        ans = mx
        
        def good(cap):
            index = 0
            took = 0
            while index < len(nums):
                if nums[index] <= cap:
                    took += 1
                    index += 1
                index += 1
            return took >= k
        
        while left <= right:
            mid = (left + right)//2
            if good(mid):
                ans = mid
                right = mid - 1
            else:
                left = mid + 1
        return ans
