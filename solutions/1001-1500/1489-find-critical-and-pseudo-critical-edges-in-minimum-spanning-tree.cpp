class Solution {
public:
    struct dsu {
        vector<int> parent;
        vector<int> size_;

        dsu(int n) {
            parent = vector<int>(n);
            for (int i = 0; i < n; i++) parent[i] = i;
            size_ = vector<int>(n, 1);
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
            return true;
        }
    };
    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {
        int m = (int) edges.size();
        vector<int> order(m);
        iota(order.begin(), order.end(), 0);
        sort(order.begin(), order.end(), [&](int i, int j) {
           return edges[i][2] < edges[j][2]; 
        });
        
        auto kruskal = [&](dsu ds, int banned=-1) {
            int sum = 0;
            for (int i = 0; i < m; i++) {
                int index = order[i];
                if (index == banned) continue;
                int u = edges[index][0], v = edges[index][1], w = edges[index][2];
                if (ds.union_(u, v)) {
                    sum += w;
                }
            }
            if (ds.size_[ds.find_(0)] < n) {
                return (int) 1e9;
            }
            return sum;
        };
        
        vector<vector<int>> ans(2);
        dsu ds(n);
        int best = kruskal(ds);
        for (int i = 0; i < m; i++) {
            int index = order[i];
            int u = edges[index][0], v = edges[index][1], w = edges[index][2];
            
            dsu ds2(n);
            int current = kruskal(ds2, index); //try without the edge
            if (current > best) {
                ans[0].push_back(index);
                continue;
            }
            
            dsu ds3(n);
            ds3.union_(u, v); 
            current = w + kruskal(ds3); //try with the edges
            if (current == best) {
                ans[1].push_back(index);
            }
        }
        return ans;
    }
};
