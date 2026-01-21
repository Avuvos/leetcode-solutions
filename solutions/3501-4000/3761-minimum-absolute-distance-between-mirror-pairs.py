class Solution:
    def minMirrorPairDistance(self, nums: List[int]) -> int:
        INF = 10 ** 9
        mp = {}
        res = INF
        for i, x in enumerate(nums[::-1]):
            r = int(str(x)[::-1])
            if r in mp:
                res = min(res, abs(i - mp[r]))
            mp[x] = i
        return res if res < INF else -1
