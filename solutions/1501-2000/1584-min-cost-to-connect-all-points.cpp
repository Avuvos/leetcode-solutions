class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = (int) points.size();
        vector<tuple<int, int, int>> edges;
        for (int i = 0; i < n; i++) {
            int x = points[i][0], y = points[i][1];
            for (int j = i + 1; j < n; j++) {
                int nx = points[j][0], ny = points[j][1];
                int d = abs(x - nx) + abs(y - ny);
                edges.push_back({d, i, j});
            }
        }
        sort(edges.begin(), edges.end());
        vector<int> parent(n);
        vector<int> sz(n, 1);
        iota(parent.begin(), parent.end(), 0);
        // function<int(int)> _find = [&](int x) {
        //     return x == parent[x] ? x : parent[x] = _find(parent[x]);
        // };
        
        function<int(int)> _find = [&](int x) {
            int root = x;
            while (root != parent[root]) {
                root = parent[root];
            }
            //Path compression
            while (parent[x] != root) {
                int p = parent[x];
                parent[x] = root;
                x = p;
            }
            return root;
        };
        
        function<bool(int, int)> _union = [&](int x, int y) {
            int X = _find(x), Y = _find(y);
            if (X == Y) return false;
            if (sz[X] < sz[Y]) swap(X, Y);
            sz[X] += sz[Y];
            parent[Y] = X;
            return true;
        };
        
        int ans = 0;
        for (auto [w, u, v]: edges) {
            if (_union(u, v)) {
                ans += w;
            }
        };
        return ans;
    }
};
