from sortedcontainers import SortedList
import bisect
class Solution:
    def countOperationsToEmptyArray(self, nums: List[int]) -> int:
        ans = 0
        n = len(nums)
        l = sorted([x for x in nums])
        
        prev = defaultdict(int)
        dp = defaultdict(int)
        dp[min(nums)] = 1
        pos = defaultdict(int)
        
        for i, num in enumerate(nums):
            pos[num] = i
            idx = bisect.bisect_left(l, num)
            if idx == 0: continue
            prev[num] = l[idx - 1]
        
        ans += 1
        for i, num in enumerate(l):
            if i == 0: continue
            idx = pos[num]
            p = l[i - 1]
            dp[num] = dp[p]
            if idx < pos[p]:
                dp[num] += 1
            ans += dp[num]
        return ans
                
