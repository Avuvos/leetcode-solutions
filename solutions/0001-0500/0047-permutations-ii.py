class Solution:
    def permuteUnique(self, nums: List[int]) -> List[List[int]]:
        res = []
        nums.sort()
        
        def dfs(nums, path):
            if len(nums) == 0:
                res.append(path.copy())
                return
            for i in range(len(nums)):
                if i == 0 or nums[i] != nums[i-1]:
                    path.append(nums[i])
                    dfs(nums[:i] + nums[i+1:] ,path)
                    path.pop()
                    
        dfs(nums, [])
        return res
        
