class Solution:
    def makesquare(self, matchsticks: List[int]) -> bool:
        if sum(matchsticks) % 4 != 0:
            return False
        target = sum(matchsticks) // 4
        matchsticks.sort(reverse=True)
        
        @cache
        def dfs(i, a, b, c, d):
            if i >= len(matchsticks):
                return a == b and b == c and c == d
            cur = matchsticks[i]
            s1 = s2 = s3 = s4 = False
            if a - cur >= 0: s1 = dfs(i + 1, a - cur, b, c, d)
            if b - cur >= 0: s2 = dfs(i + 1, a, b - cur, c, d)
            if c - cur >= 0: s3 = dfs(i + 1, a, b, c - cur, d)
            if d - cur >= 0: s4 = dfs(i + 1, a, b, c, d - cur)
            return s1 or s2 or s3 or s4
        return dfs(0, target, target, target, target)
        
