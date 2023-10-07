class TreeAncestor {
public:
    vector<vector<int>> g;
    vector<int> dep;
    vector<vector<int>> up;
    const int LOG = 18;
    int root = -1;
    TreeAncestor(int n, vector<int>& parent) {
        g.resize(n);
        dep.resize(n);
        up = vector<vector<int>>(LOG, vector<int>(n));
        for (int i = 0; i < n; i++) {
            if (parent[i] != -1) {
                g[parent[i]].push_back(i);
            } else {
                root = i;
            }
        }
        
        auto dfs = [&](auto dfs, int u, int p) -> void {
            for (auto &v: g[u]) {
                if (v == p) continue;
                dep[v] = 1 + dep[u];
                dfs(dfs, v, u);
            }
        };
        
        dep[root] = 0;
        dfs(dfs, root, -1);
        for (int i = 0; i < n; i++) {
            up[0][i] = parent[i];
        }
        up[0][root] = root;
        for (int i = 1; i < LOG; i++) {
            for (int j = 0; j < n; j++) {
                up[i][j] = up[i - 1][up[i - 1][j]];
            }
        }
    }
    
    int getKthAncestor(int node, int k) {
        if (dep[node] < k) {
            return -1;
        }
        for (int i = LOG - 1; i >= 0; i--) {
            if ((k >> i) & 1) {
                node = up[i][node];
            }
        }
        return node;
    }
};

/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */
