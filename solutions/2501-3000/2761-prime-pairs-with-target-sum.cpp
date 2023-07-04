class Solution {
public:
    vector<vector<int>> findPrimePairs(int n) {
        vector<bool> is_prime(n + 1, true);
        for (int i = 2; i * i <= n; i++) {
            if (!is_prime[i]) continue;
            for (int j = i * i; j <= n; j += i) {
                is_prime[j] = false;
            }
        }
        vector<vector<int>> ans;
        for (int x = 2; x <= n; x++) {
            int y = n - x;
            if (y < x) break;
            if (!is_prime[x] || !is_prime[y]) continue;
            ans.push_back({x, y});
        }
        return ans;
    }
};
