class Solution:
    def maximumCostSubstring(self, s: str, chars: str, vals: List[int]) -> int:
        lst = []
        ab = "abcdefghijklmnopqrstuvwxyz"
        mp = defaultdict(int)
        for i, c in enumerate(ab):
            mp[c] = i + 1
        for c, v in zip(chars, vals):
            mp[c] = v
        lst = [mp[c] for c in s]
        
        cur = lst[0]
        ans = max(lst[0], 0)
        for i in range(1, len(lst)):
            cur = max(lst[i], cur + lst[i])
            ans = max(ans, cur)
        return ans
        
        
