class Solution {
public:
    struct SegmentTree {
        int n;
        vector<int> tree;
        SegmentTree(int size) : n(size), tree(2 * size, 0) {}

        void modify(int p, int value) {
            p += n;
            tree[p] = max(tree[p], value);
            for (p >>= 1; p > 0; p >>= 1) {
                tree[p] = max(tree[p << 1], tree[p << 1 | 1]);
            }
        }

        int max_query(int l, int r) {
            int res = 0;
            for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
                if (l & 1) {
                    res = max(res, tree[l]);
                    l++;
                }
                if (r & 1) {
                    --r;
                    res = max(res, tree[r]);
                }
            }
            return res;
        }
    };

    int computeLIS(vector<pair<int, int>>& points) {
        if (points.empty()) return 0;
        vector<int> ys;
        for (auto& [x, y] : points) {
            ys.push_back(y);
        }
        sort(ys.begin(), ys.end());
        ys.erase(unique(ys.begin(), ys.end()), ys.end());
        unordered_map<int, int> y_to_index;
        int n = ys.size();
        for (int i = 0; i < n; ++i) {
            y_to_index[ys[i]] = i;
        }
        sort(points.begin(), points.end());
        SegmentTree st(n);

        int res = 1;
        int i = 0;
        while (i < points.size()) {
            int x = points[i].first;
            int j = i;
            vector<pair<int, int>> temp;
            while (j < points.size() && points[j].first == x) {
                int y = points[j].second;
                int y_idx = y_to_index[y];
                int len = st.max_query(0, y_idx) + 1;
                res = max(res, len);
                temp.emplace_back(y_idx, len);
                ++j;
            }
            for (auto& [y_idx, len] : temp) {
                st.modify(y_idx, len);
            }
            i = j;
        }
        return res;
    }

    int maxPathLength(vector<vector<int>>& coordinates, int k) {
        int n = coordinates.size();
        int xk = coordinates[k][0], yk = coordinates[k][1];

        vector<pair<int, int>> prefix_points;
        vector<pair<int, int>> suffix_points;

        for (int i = 0; i < n; ++i) {
            if (i == k) continue;
            int xi = coordinates[i][0];
            int yi = coordinates[i][1];
            if (xi < xk && yi < yk) {
                prefix_points.emplace_back(xi, yi);
            } else if (xi > xk && yi > yk) {
                suffix_points.emplace_back(xi, yi);
            }
        }

        int length_prefix = computeLIS(prefix_points);
        int length_suffix = computeLIS(suffix_points);

        return 1 + length_prefix + length_suffix;
    }
};
