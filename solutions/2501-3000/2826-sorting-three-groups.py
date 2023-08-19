class Solution:
    def minimumOperations(self, nums: List[int]) -> int:
        
        @cache
        def dfs(i, prev):
            if i >= len(nums):
                return 0
            ans = 1e9
            cur = 1e9
            for x in range(1, 4):
                if x >= prev:
                    add = 0
                    if x != nums[i]:
                        add = 1
                    cur = add + dfs(i + 1, max(prev, x))
                    ans = min(ans, cur)
            return ans
        
        return dfs(0, -1)
                
