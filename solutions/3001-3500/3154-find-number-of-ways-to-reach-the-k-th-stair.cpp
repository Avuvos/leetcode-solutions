class Solution {
public:
    int waysToReachStair(int k) {
        
        // map<tuple<int, int, int>, int> dp;
        vector<vector<unordered_map<int, int>>> dp(30, vector<unordered_map<int, int>>(2));
        auto dfs = [&](auto dfs, int stair, int used, int jump) -> int {
            if (stair > k + 2 || jump > 30) {
                return 0;
            }
            if (dp[jump][used].find(stair) != dp[jump][used].end()) {
                return dp[jump][used][stair];
            }
            // if (dp.find({stair, used, jump}) != dp.end()) {
            //     return dp[{stair, used, jump}];
            // }
            
            int ans = (stair == k ? 1 : 0);
            if (!used && stair > 0) {
                ans += dfs(dfs, stair - 1, 1, jump);
            }
            ans += dfs(dfs, stair + (1 << jump), 0, jump + 1);
            return dp[jump][used][stair] = ans;
            // return dp[{stair, used, jump}] = ans;
        };
        
        return dfs(dfs, 1, 0, 0);
    }
};
