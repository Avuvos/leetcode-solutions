class Solution {
public:
    int countWinningSequences(string s) {
        const int MOD = 1e9 + 7;
        int n = s.size();
        vector<vector<vector<long long>>> dp(n, vector<vector<long long>>(2 * n + 1, vector<long long>(4, -1)));
        vector<char> creatures = {'F', 'W', 'E'};
        auto dfs = [&](auto &dfs, int index, int delta, int prev) -> long long {
            if (index >= n) {
                return delta > 0;
            }
            if (dp[index][n + delta][prev] != -1) {
                return dp[index][n + delta][prev];
            }
            char alice_c = s[index];
            long long ways = 0;
            for (int i = 0; i < 3; i++) {
                if (i == prev) continue;
                char bob_c = creatures[i];
                bool bob_wins = ((bob_c == 'F' && alice_c == 'E') ||
                                 (bob_c == 'W' && alice_c == 'F') ||
                                 (bob_c == 'E' && alice_c == 'W')); 
                int add = bob_c == alice_c ? 0 : bob_wins ? 1 : -1;
                ways = (ways + dfs(dfs, index + 1, delta + add, i) % MOD) % MOD;
            }
            return dp[index][n + delta][prev] = ways;
        };
        return dfs(dfs, 0, 0, 3);
    }
};
