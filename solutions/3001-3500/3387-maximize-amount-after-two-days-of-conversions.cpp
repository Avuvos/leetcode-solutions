class Solution {
public:
    double maxAmount(string initialCurrency, vector<vector<string>>& pairs1, vector<double>& rates1, vector<vector<string>>& pairs2, vector<double>& rates2) {
        
        auto build = [&](vector<vector<string>>& pairs, vector<double>& rates) {
            map<string, vector<pair<string, double>>> g;
            for (int i = 0; i < rates.size(); i++) {
                string u = pairs[i][0], v = pairs[i][1];
                double w = rates[i];
                g[u].emplace_back(v, w);
                g[v].emplace_back(u, 1.0 / w);
            }
            return g;
        };
        
        auto dfs = [&](auto &dfs, string u, map<string, vector<pair<string, double>>> g, map<string, double> &dp) -> void {
            for (auto &[v, w]: g[u]) {
                double val = dp[u] * w;
                if (!dp.contains(v) || dp[v] < val) {
                    dp[v] = val;
                    dfs(dfs, v, g, dp);
                }
            }
        };
        
        auto g1 = build(pairs1, rates1);
        auto g2 = build(pairs2, rates2);
        
        map<string, double> dp1;
        dp1[initialCurrency] = 1.0;
        dfs(dfs, initialCurrency, g1, dp1);
        
        double best = max(1.0, dp1[initialCurrency]);      
        for (auto &[str, val]: dp1) {
            map<string, double> dp2;
            dp2[str] = val;
            dfs(dfs, str, g2, dp2);
            best = max(best, dp2[initialCurrency]);
        }
        return best;
        
    }
};
