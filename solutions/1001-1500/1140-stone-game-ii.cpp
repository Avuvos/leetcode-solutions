class Solution {
public:
    int stoneGameII(vector<int>& piles) {
        int n = (int) piles.size();
        int memo[101][101][2];
        memset(memo, -1, sizeof(memo));
        function<int(int, int, bool)> dfs = [&](int index, int M, int alice) {
            if (index >= n) return 0;
            if (memo[index][M][alice] != -1) return memo[index][M][alice];
            int res = alice ? 0 : 1e9, sum = 0;
            for (int x = 1; x <= 2*M && index + x - 1 < n; x++) {
                sum += piles[index + x - 1];
                int cur = dfs(index + x, max(x, M), 1 - alice);
                if (alice) {
                    cur += sum;
                    res = max(res, cur);
                } else {
                    res = min(res, cur);
                }
            }
            memo[index][M][alice] = res;
            return res;
        };
        return dfs(0, 1, 1);
    }
};
