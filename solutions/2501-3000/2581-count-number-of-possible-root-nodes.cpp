class Solution {
public:
    set<pair<int, int>> s;
    int ans = 0;
    int localk = 0;
    int realk = 0;
    vector<vector<int>> g;

    void dfs(int u, int p) {
        for (auto &v: g[u]) {
            if (v == p) continue;
            if (s.find({u, v}) != s.end()) {
                localk++;
            }
            dfs(v, u);
        }
    }

    void dfs2(int u, int p) {
        //now the new root is u
        if (s.find({p, u}) != s.end()) {
            localk--;
        }
        if (s.find({u, p}) != s.end()) {
            localk++;
        }
        if (localk >= realk) {
            ans++;
        }
        for (auto &v: g[u]) {
            if (v == p) continue;
            dfs2(v, u);
        }
        if (s.find({p, u}) != s.end()) {
            localk++;
        }
        if (s.find({u, p}) != s.end()) {
            localk--;
        }
    }

    int rootCount(vector<vector<int>>& edges, vector<vector<int>>& guesses, int k) {
        int N = (int) guesses.size(), n = (int) edges.size() + 1;
        g = vector<vector<int>>(n + 1);
        for (auto e: edges) {
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);
        }
        for (auto &gs: guesses) {
            s.insert(make_pair(gs[0], gs[1]));
        }
        ans = 0;
        localk = 0;
        realk = k;
        dfs(1, -1);
        dfs2(1, -1);
        return ans;
    }
};
