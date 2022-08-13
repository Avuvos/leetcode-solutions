class Solution:
    def longestIdealString(self, s: str, k: int) -> int:
        n = len(s)
        dp = [1] * (n + 1)
        dic = defaultdict(int)
        dic[s[0]] = 0
        for i in range(1, n):
            curr_char = s[i]
            for c in ascii_lowercase:
                if c in dic:
                    if abs(ord(curr_char) - ord(c)) <= k:
                        dp[i + 1] = max(dp[i + 1], 1 + dp[dic[c]])
            dic[curr_char] = i + 1
        return max(dp)


