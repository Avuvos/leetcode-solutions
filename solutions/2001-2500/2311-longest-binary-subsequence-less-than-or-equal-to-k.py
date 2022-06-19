class Solution:
    def longestSubsequence(self, s: str, k: int) -> int:
        s = s[::-1]
        curr = 0
        counter = 0
        for i in range(len(s)):
            if s[i] == '1' and curr + 2**i <= k:
                counter += 1
                curr += 2**i
            elif s[i] == '0':
                counter += 1
        return counter
