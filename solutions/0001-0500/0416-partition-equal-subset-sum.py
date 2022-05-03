class Solution:
    def canPartition(self, nums: List[int]) -> bool:
        s = sum(nums)
        if s % 2 == 1: return False
        target = s // 2
        
        @cache
        def dfs(curr, idx):
            if curr == target:
                return True
            if curr > target or idx >= len(nums):
                return False
            return dfs(curr + nums[idx], idx + 1) or dfs(curr, idx + 1)
        return dfs(0, 0)
            
            
        
        
        
        
