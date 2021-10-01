class Solution:
    def subsetsWithDup(self, nums: List[int]) -> List[List[int]]:
        
        subsets = []
        nums.sort()
        
        def dfs(nums, curr):
            subsets.append(curr.copy())
            for i in range(len(nums)):
                if i == 0 or nums[i] != nums[i-1]:
                    curr.append(nums[i])
                    dfs(nums[i+1:] , curr)
                    curr.pop()
                    
        dfs(nums, [])
        return subsets
