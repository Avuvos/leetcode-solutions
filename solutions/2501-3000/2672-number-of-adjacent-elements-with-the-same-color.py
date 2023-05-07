class Solution:
    def colorTheArray(self, n: int, queries: List[List[int]]) -> List[int]:
        ans = [0 for i in range(len(queries))]
        nums = [0 for i in range(n)]
        cur = 0
        
        for i, (index, color) in enumerate(queries):
            if nums[index] != 0 and index - 1 >= 0 and nums[index] == nums[index - 1]:
                cur -= 1
            if nums[index] != 0 and index + 1 < n and nums[index] == nums[index + 1]:
                cur -= 1
            nums[index] = color
            if index - 1 >= 0 and nums[index] == nums[index - 1]:
                cur += 1
            if index + 1 < n and nums[index] == nums[index + 1]:
                cur += 1
            ans[i] = cur
        return ans
        
        
