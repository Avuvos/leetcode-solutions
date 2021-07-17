class Solution:
    def thirdMax(self, nums: List[int]) -> int:
        if len(nums) < 3:
            return max(nums)
        else:
            max_1 = max(nums)
            max_2 = float('-inf')
            max_3 = float('-inf')
            for num in nums:
                if num < max_1 and num > max_2:
                    max_2 = num
            
            for num in nums:
                if num < max_1 and num < max_2 and num > max_3:
                    max_3 = num
            
            if max_3 == float('-inf'):
                return max(nums)
            else:
                return max_3
                    
          
