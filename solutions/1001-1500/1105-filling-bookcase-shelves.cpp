class Solution {
public:
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        int n = int(books.size());
        const int inf = 1e9 + 2;
        vector<vector<int>> dp(n, vector<int>(shelfWidth + 1, -1));
        auto dfs = [&](auto &dfs, int index, int width, int mx) -> int {
            if (index >= n) {
                return mx;
            }
            if (dp[index][width] != -1) {
                return dp[index][width];
            }
            int place = inf, skip = inf;
            if (width + books[index][0] <= shelfWidth) {
                place = dfs(dfs, index + 1, width + books[index][0], max(mx, books[index][1]));
            }
            skip = mx + dfs(dfs, index + 1, books[index][0] ,books[index][1]);
            return dp[index][width] = min(place, skip);
        };
        return dfs(dfs, 0, 0, 0);
    }
};
