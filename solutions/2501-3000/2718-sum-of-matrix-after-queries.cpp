class Solution {
public:
    long long matrixSumQueries(int n, vector<vector<int>>& queries) {
        vector<int> rows(n, -1), cols(n, -1);
        long long ans = 0, col_ops = 0, row_ops = 0;
        reverse(queries.begin(), queries.end());
        for (int i = 0; i < queries.size(); i++) {
            long long idx = queries[i][1], val = queries[i][2];
            if (queries[i][0] == 0) {
                if (rows[idx] != -1) continue;
                rows[idx] = val;
                ans += val * (max(0LL, n - col_ops)); 
                row_ops++;
            } else {
                if (cols[idx] != -1) continue;
                cols[idx] = val;
                ans += val * (max(0LL, n - row_ops));
                col_ops++;
            }
        }
        return ans;
    }
};
