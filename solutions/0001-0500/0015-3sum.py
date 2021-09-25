class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        
        answer = []
        n = len(nums)
        nums.sort()
        
        for i in range(n):
            curr = nums[i] #pick one element each time
            if i > 0 and nums[i-1] == curr:
                continue
                
            left = i + 1  
            right = n-1
            while left < right: #now its just two sum 2, as we look for sum = 0
                su = curr + nums[left] + nums[right]
                if su == 0:
                    answer.append([curr, nums[left], nums[right]])
                    left += 1
                    while nums[left] == nums[left-1] and left < right:
                        left += 1
                elif su < 0:
                    left += 1
                else:
                    right -= 1
                    
        return answer
                    
