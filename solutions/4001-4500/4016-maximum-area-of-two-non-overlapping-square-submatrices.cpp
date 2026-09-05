class Solution {
public:
    int maxArea(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        vector<vector<int>> ps = vector<vector<int>>(n + 1, vector<int>(m + 1, 0));
        for (int row = 1; row < n + 1; row++) {
            for (int col = 1; col < m + 1; col++) {
                ps[row][col] = mat[row - 1][col - 1] + ps[row - 1][col] + ps[row][col - 1] - ps[row - 1][col - 1];
            }
        }
        auto sum_region = [&](int top_row, int left_col, int bot_row, int right_col) -> int {
            return ps[bot_row + 1][right_col + 1]
            - ps[bot_row + 1][left_col] 
            - ps[top_row][right_col + 1]
            + ps[top_row][left_col];
        };

        auto ok = [&](int k) -> bool {
            int max_i = -1, max_j = -1;
            int min_i = 1e9, min_j = 1e9;
            for (int i = 0; i < n - k + 1; i++) {
                for (int j = 0; j < m - k + 1; j++) {
                    if (sum_region(i, j, i + k - 1, j + k - 1) == k * k) {
                        max_i = max(max_i, i);
                        min_i = min(min_i, i);
                        max_j = max(max_j, j);
                        min_j = min(min_j, j);
                    }
                }
            }
            if (max_i == -1) return false;
            return max_i - min_i >= k || max_j - min_j >= k;
        };

        int left = 0, right = min(n, m), ans = 0;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (ok(mid)) {
                ans = mid;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return ans * ans;
    }
};
