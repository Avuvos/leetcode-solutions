class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string, vector<pair<string, double>>> g;
        for (int i = 0; i < equations.size(); i++) {
            g[equations[i][0]].emplace_back(equations[i][1], values[i]);
            g[equations[i][1]].emplace_back(equations[i][0], 1.0/values[i]);
        }
        set<string> seen;
        function<double(string&, string&)> dfs = [&](string& current, string& target) {
            if (current == target) {
                return 1.0;
            }
            for (auto [neib, val]: g[current]) {
                if (seen.find(neib) != seen.end()) {
                    continue;
                }
                seen.insert(neib);
                double res = val * dfs(neib, target);
                if (res > 0) return res;
            }
            return -1.0;
        };

        vector<double> ans(queries.size());
        for (int i = 0; i < queries.size(); i++) {
            string a = queries[i][0], b = queries[i][1];
            if (g.find(a) == g.end() || g.find(b) == g.end()) {
                ans[i] = -1.0;
                continue;
            }
            seen.clear();
            seen.insert(a);
            ans[i] = dfs(a, b);
        }
        return ans;
    }
};
