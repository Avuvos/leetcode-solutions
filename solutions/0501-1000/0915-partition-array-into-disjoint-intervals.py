class Solution:
    def partitionDisjoint(self, nums: List[int]) -> int:
        n = len(nums)
        
        max_prefix = [nums[0]]
        min_suffix = [nums[n - 1]]
        
        for i in range(1, n):
            max_prefix.append(max(max_prefix[i - 1], nums[i]))
            min_suffix.append(min(min_suffix[i - 1], nums[n - i - 1]))
            
        for i in range(1, n):
            if max_prefix[i - 1] <= min_suffix[n - i - 1]:
                return i
        return -1
            
