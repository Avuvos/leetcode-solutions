class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        pos = {}
        left = res = 0
        for right, ch in enumerate(s):
            left = max(left, pos.get(ch, -1) + 1)
            res = max(res, right - left + 1)
            pos[ch] = right
        return res

