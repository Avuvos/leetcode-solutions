class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        int m = mat.size();
        vector<int> s(m);
        for (int i = 0; i < m; i++) {
            s[i] = accumulate(mat[i].begin(), mat[i].end(), 0);
        }
        vector<int> order(m);
        iota(order.begin(), order.end(), 0);
        sort(order.begin(), order.end(), [&](const int &i, const int &j) {
            return s[i] != s[j] ? s[i] < s[j] : i < j;
        });
        order.resize(k);
        return order;
    }
};
