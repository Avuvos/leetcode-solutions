class Solution:
    def countBadPairs(self, nums: List[int]) -> int:
        dic = defaultdict(int)
        n = len(nums)
        res = 0
        for i, x in enumerate(nums):
            res += dic[x - i]
            dic[x - i] += 1
        return n*(n-1)//2 - res
