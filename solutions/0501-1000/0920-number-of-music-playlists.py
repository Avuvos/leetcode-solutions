class Solution:
    def numMusicPlaylists(self, n: int, goal: int, k: int) -> int:
        MOD = 10**9 + 7
        
        @cache
        def dfs(left, uniq):
            if left == 0 and uniq == 0:
                return 1
            if left == 0 or uniq == 0:
                return 0
            ans = (dfs(left - 1, uniq - 1) * (n - uniq + 1)) % MOD
            ans += (dfs(left - 1, uniq) * (max(0, uniq - k))) % MOD
            return ans % MOD
        
        return dfs(goal, n)
