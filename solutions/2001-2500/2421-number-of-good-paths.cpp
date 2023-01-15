struct dsu {
    vector<int> parent;
    vector<int> size_;
    vector<int> cnt;
    vector<int> val;

    dsu(int n) {
        parent = vector<int>(n);
        for (int i = 0; i < n; i++) parent[i] = i;
        size_ = vector<int>(n, 1);
        cnt = vector<int>(n, 0);
        val = vector<int>(n, -1);
    }

    int find_(int x) {
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
    }
    bool union_(int x,int y) {
        int X = find_(x);
        int Y = find_(y);
        // x and y are already in the same set
        if (X == Y) return false;

        // x and y are not in same set, so we merge them
        if (size_[X] < size_[Y]) swap(X, Y);

        // merge yRoot into xRoot
        parent[Y] = X;
        size_[X] += size_[Y];
        cnt[X] += cnt[Y];
        return true;
    }
};

class Solution {
public:
    int numberOfGoodPaths(vector<int>& vals, vector<vector<int>>& edges) {
        int n = (int)vals.size();
        dsu uf(n);
        vector<vector<int>> g = vector<vector<int>>(n);
        for (auto e: edges) {
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);
        }
        vector<vector<int>> values(*max_element(vals.begin(), vals.end()) + 1);
        for (int i = 0; i < n; i++) {
            values[vals[i]].push_back(i);
        }
        int res = 0;
        vector<bool> seen(n, false);
        for (int i = 0; i < values.size(); i++) {
            int val = i;
            vector<int> vec = values[i];
            for (auto& node: vec) {
                int np = uf.find_(node);
                if (uf.val[np] != val) {
                    uf.val[np] = val;
                    uf.cnt[np] = 1;
                }
                for (auto& neib: g[node]) {
                    int nb = uf.find_(neib);
                    if (uf.val[nb] != val) {
                        uf.val[nb] = val;
                        uf.cnt[nb] = vals[neib] == vals[node];
                    }
                    if (vals[neib] <= vals[node]) {
                        uf.union_(node, neib);
                    }
                }
            }
            unordered_set<int> vis;
            for (auto& node: vec) {
                int np = uf.find_(node);
                if (vis.find(np) != vis.end()) continue;
                vis.insert(np);
                res += ((uf.cnt[np])*(uf.cnt[np] - 1))/2;
                
            }
        }
        return res + n;
    }
};
