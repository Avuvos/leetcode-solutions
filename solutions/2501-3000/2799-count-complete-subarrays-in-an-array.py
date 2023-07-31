class Solution:
    def countCompleteSubarrays(self, nums: List[int]) -> int:
        s = set(nums)
        ans = 0
        for i in range(len(nums)):
            cur = set()
            for j in range(i, len(nums)):
                cur.add(nums[j])
                if len(cur) == len(s): ans += 1;
        return ans
