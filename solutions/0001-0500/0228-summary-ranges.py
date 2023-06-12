class Solution:
    def summaryRanges(self, nums: List[int]) -> List[str]:
        ans = []
        if not nums:
            return ans
        if len(nums) == 1:
            return [f'{nums[0]}']
        left = 0
        for right in range(1, len(nums)):
            if nums[right] == nums[right - 1] + 1:
                continue
            if left == right - 1:
                ans.append(f'{nums[left]}')
            else:
                ans.append(f'{nums[left]}->{nums[right - 1]}')
            left = right
        
        right = len(nums)
        if left == right - 1:
            ans.append(f'{nums[left]}')
        else:
            ans.append(f'{nums[left]}->{nums[right - 1]}')    
        return ans
