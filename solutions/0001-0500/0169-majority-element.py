class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        if len(nums) == 0:
            return None
        if len(nums) == 1:
            return nums[0]
        
        half = len(nums)//2
        
        first = self.majorityElement(nums[half:])
        second = self.majorityElement(nums[:half])
        
        if nums.count(first) > half:
            return first
        if nums.count(second) > half:
            return second
        
        return None #shouldnt get here
