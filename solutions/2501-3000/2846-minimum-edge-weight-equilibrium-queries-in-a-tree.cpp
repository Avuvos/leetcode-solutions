class Solution {
public:

    template<typename T, bool maximum_mode = false>
    struct RMQ {
        static int highest_bit(unsigned x) {
            return x == 0 ? -1 : 31 - __builtin_clz(x);
        }

        int n = 0;
        vector<T> values;
        vector<vector<int>> range_low;

        RMQ(const vector<T> &_values = {}) {
            if (!_values.empty())
                build(_values);
        }

        // Note: when `values[a] == values[b]`, returns b.
        int better_index(int a, int b) const {
            return (maximum_mode ? values[b] < values[a] : values[a] < values[b]) ? a : b;
        }

        void build(const vector<T> &_values) {
            values = _values;
            n = int(values.size());
            int levels = highest_bit(n) + 1;
            range_low.resize(levels);

            for (int k = 0; k < levels; k++)
                range_low[k].resize(n - (1 << k) + 1);

            for (int i = 0; i < n; i++)
                range_low[0][i] = i;

            for (int k = 1; k < levels; k++)
                for (int i = 0; i <= n - (1 << k); i++)
                    range_low[k][i] = better_index(range_low[k - 1][i], range_low[k - 1][i + (1 << (k - 1))]);
        }

        // Note: breaks ties by choosing the largest index.
        int query_index(int a, int b) const {
            assert(0 <= a && a < b && b <= n);
            int level = highest_bit(b - a);
            return better_index(range_low[level][a], range_low[level][b - (1 << level)]);
        }

        T query_value(int a, int b) const {
            return values[query_index(a, b)];
        }
    };

    struct LCA {
        int n = 0;
        vector<vector<int>> adj;
        vector<int> parent, depth, subtree_size;
        vector<int> euler, first_occurrence;
        vector<int> tour_start, tour_end, postorder;
        vector<int> tour_list, rev_tour_list;
        vector<int> heavy_root;
        RMQ<int> rmq;
        bool built;

        LCA(int _n = 0) {
            init(_n);
        }

        // Warning: this does not call build().
        LCA(const vector<vector<int>> &_adj) {
            init(_adj);
        }

        void init(int _n) {
            n = _n;
            adj.assign(n, {});
            parent.resize(n);
            depth.resize(n);
            subtree_size.resize(n);
            first_occurrence.resize(n);
            tour_start.resize(n);
            tour_end.resize(n);
            postorder.resize(n);
            tour_list.resize(n);
            heavy_root.resize(n);
            built = false;
        }

        // Warning: this does not call build().
        void init(const vector<vector<int>> &_adj) {
            init(int(_adj.size()));
            adj = _adj;
        }

        void add_edge(int a, int b) {
            adj[a].push_back(b);
            adj[b].push_back(a);
        }

        int degree(int v) const {
            return int(adj[v].size()) + (built && parent[v] >= 0);
        }

        void dfs(int node, int par) {
            parent[node] = par;
            depth[node] = par < 0 ? 0 : depth[par] + 1;
            subtree_size[node] = 1;

            // Erase the edge to parent.
            adj[node].erase(remove(adj[node].begin(), adj[node].end(), par), adj[node].end());

            for (int child : adj[node]) {
                dfs(child, node);
                subtree_size[node] += subtree_size[child];
            }

            // Heavy-light subtree reordering.
            sort(adj[node].begin(), adj[node].end(), [&](int a, int b) {
                return subtree_size[a] > subtree_size[b];
            });
        }

        int tour, post_tour;

        void tour_dfs(int node, bool heavy) {
            heavy_root[node] = heavy ? heavy_root[parent[node]] : node;
            first_occurrence[node] = int(euler.size());
            euler.push_back(node);
            tour_list[tour] = node;
            tour_start[node] = tour++;
            bool heavy_child = true;

            for (int child : adj[node]) {
                tour_dfs(child, heavy_child);
                euler.push_back(node);
                heavy_child = false;
            }

            tour_end[node] = tour;
            postorder[node] = post_tour++;
        }

        void build(int root = -1, bool build_rmq = true) {
            parent.assign(n, -1);

            if (0 <= root && root < n)
                dfs(root, -1);

            for (int i = 0; i < n; i++)
                if (i != root && parent[i] < 0)
                    dfs(i, -1);

            tour = post_tour = 0;
            euler.clear();
            euler.reserve(2 * n);

            for (int i = 0; i < n; i++)
                if (parent[i] < 0) {
                    tour_dfs(i, false);
                    // Add a -1 in between connected components to help us detect when nodes aren't connected.
                    euler.push_back(-1);
                }

            rev_tour_list = tour_list;
            reverse(rev_tour_list.begin(), rev_tour_list.end());
            assert(int(euler.size()) == 2 * n);
            vector<int> euler_depths;
            euler_depths.reserve(euler.size());

            for (int node : euler)
                euler_depths.push_back(node < 0 ? node : depth[node]);

            if (build_rmq)
                rmq.build(euler_depths);

            built = true;
        }

        // Note: returns -1 if `a` and `b` aren't connected.
        int get_lca(int a, int b) const {
            a = first_occurrence[a];
            b = first_occurrence[b];

            if (a > b)
                swap(a, b);

            return euler[rmq.query_index(a, b + 1)];
        }
    };

    vector<int> minOperationsQueries(int n, vector<vector<int>>& edges, vector<vector<int>>& queries) {
        int m = (int) queries.size();
        vector<int> ans(m);
        LCA lca(n);
        vector<vector<pair<int, int>>> g(n);
        for (auto e: edges) {
            lca.add_edge(e[0], e[1]);
            g[e[0]].push_back(make_pair(e[1], e[2]));
            g[e[1]].push_back(make_pair(e[0], e[2]));
        }
        
        lca.build();
        
        vector<vector<int>> cnt(n, vector<int>(27, 0));
        function<void(int, int)> dfs = [&](int u, int p) {
            for (auto &[v, w]: g[u]) {
                if (v == p) continue;
                for (int i = 1; i <= 26; i++) {
                    cnt[v][i] = cnt[u][i];
                }
                cnt[v][w]++;
                dfs(v, u);
            }
        };
        dfs(0, -1);
        
        for (int q = 0; q < m; q++) {
            int a = queries[q][0], b = queries[q][1];
            int lc = lca.get_lca(a, b);
            int mx = 0, sum = 0;
            for (int i = 1; i <= 26; i++) {
                int x = cnt[a][i] + cnt[b][i] - 2 * cnt[lc][i];
                mx = max(mx, x);
                sum += x;
            }
            ans[q] = sum - mx;
        }
        return ans;
    }
};
