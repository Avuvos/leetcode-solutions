class Solution:
    def countPairs(self, words: List[str]) -> int:
        mp = defaultdict(int)
        ans = 0
        for s in words:
            offset = ord('z') - ord(s[0])
            ns = "".join([chr(ord('a') + (ord(c) - ord('a') + offset) % 26) for c in s])
            ans += mp[ns]
            mp[ns] += 1
        return ans
