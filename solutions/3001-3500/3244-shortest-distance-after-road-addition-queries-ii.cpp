struct dsu {
    vector<int> parent;
    vector<int> size_;
    vector<int> nxt;
    dsu(int n) {
        parent.resize(n);
        iota(parent.begin(), parent.end(), 0);
        size_.resize(n, 1);
        nxt.resize(n);
        iota(nxt.begin(), nxt.end(), 0);
    }

    int find_(int x) {
        return x == parent[x] ? x : parent[x] = find_(parent[x]);
    }
    bool union_(int x,int y) {
        int X = find_(x), Y = find_(y);
        if (X == Y) {
            return false;
        }
        if (size_[X] < size_[Y]) {
            swap(X, Y);
        }
        parent[Y] = X;
        size_[X] += size_[Y];
        nxt[X] = max(nxt[X], nxt[Y]);
        return true;
    }
};

class Solution {
public:
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        dsu ds(n + 1);
        int q = (int) queries.size();
        vector<int> ans(q);
        int res = n - 1;
        for (int i = 0; i < q; i++) {
            int u = queries[i][0], v = queries[i][1];
            for (int x = ds.nxt[ds.find_(u)]; x < v - 1; x = ds.nxt[ds.find_(x)]) {
                if (ds.union_(x, x + 1)) {
                    res--;
                }
            }
            ans[i] = res;
        }
        return ans;
    }
};
