class Solution:
    def countSteppingNumbers(self, low: str, high: str) -> int:
        MOD = 10**9 + 7
        
        @cache
        def dfs(s, index, tight, last, allZero):
            if index >= len(s):
                return not allZero
            bound = int(s[index]) if tight else 9
            ans = 0
            for digit in range(bound + 1):
                if last != -1 and abs(last - digit) != 1 and not allZero: continue
                ans += dfs(s,
                           index + 1,
                           tight and s[index] == str(digit),
                           digit,
                           allZero and digit == 0)
                ans %= MOD
            return ans
        
        return (dfs(high, 0, True, -1, True) - dfs(str(int(low) - 1), 0, True, -1, True)) % MOD
    
