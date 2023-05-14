class Solution:
    def maxScore(self, nums: List[int]) -> int:
        
        m = len(nums)
        n = m // 2
        mask = 0
        
        @cache
        def dfs(ops, mask):
            if ops > n:
                return 0
            ans = 0
            for i in range(m):
                for j in range(i + 1, m):
                    if (mask >> i) & 1 or (mask >> j) & 1:
                        continue
                    next_mask = mask
                    next_mask |= (1 << i)
                    next_mask |= (1 << j)
                    ans = max(ans, ops * gcd(nums[i], nums[j]) + dfs(ops + 1, next_mask))
            return ans
        return dfs(1, 0)
