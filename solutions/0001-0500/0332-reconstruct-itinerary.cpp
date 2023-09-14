class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        map<string, multiset<string>> g;
        for (auto e: tickets) {
            g[e[0]].insert(e[1]);
        }
        vector<string> ans;
        function<void(string&)> dfs = [&](string &u) {
            while (!g[u].empty()) {
                string v = *g[u].begin();
                g[u].erase(g[u].find(v));
                dfs(v);
            }
            ans.push_back(u);
        };
        string start = "JFK";
        dfs(start);
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
