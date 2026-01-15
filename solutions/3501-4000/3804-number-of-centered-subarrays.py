class Solution:
    def centeredSubarrays(self, nums: List[int]) -> int:
        res = 0
        n = len(nums)
        for i in range(n):
            _sum = 0
            s = set()
            for j in range(i, n):
                s.add(nums[j])
                _sum += nums[j]
                if _sum in s: # O(1)
                    print(i, j)
                    res += 1
        return res
