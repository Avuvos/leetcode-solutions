class Solution:
    def distinctDifferenceArray(self, nums: List[int]) -> List[int]:
        sf = Counter(nums)
        ps = defaultdict(int)
        ans = []
        p = 0
        s = len(sf)
        for i, x in enumerate(nums):
            ps[x] += 1
            sf[x] -= 1
            if sf[x] == 0: s -= 1
            if ps[x] == 1: p += 1
            ans.append(p - s)
        return ans
