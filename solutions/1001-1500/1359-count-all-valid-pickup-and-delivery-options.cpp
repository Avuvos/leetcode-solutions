class Solution {
public:
    int countOrders(int n) {
        const int MOD = 1e9 + 7;
        
        function<long long(int)> dfs = [&](int left) -> long long {
            if (left == 1) {
                return 1;
            }
            return (1LL * left * (2 * left - 1) * dfs(left - 1)) % MOD;
        };
        return dfs(n);
    }
};
