typedef long long ll;
class Solution {
public:
    int possibleStringCount(string word, int k) {
        const int MOD = 1e9 + 7;
        vector<int> buckets;
        int streak = 1;
        for (int i = 1; i < word.size(); i++) {
            if (word[i] == word[i - 1]) {
                streak++;
            } else {
                buckets.push_back(streak);
                streak = 1;
            }
        }
        buckets.push_back(streak);
        ll tot = 1;
        for (auto cnt: buckets) {
            tot = (tot * cnt) % MOD;
        }
        int n = buckets.size();
        if (n >= k) {
            return tot;
        }
        vector<int> dp(k), ndp(k), ps(k + 1);
        dp[0] = 1;
        for (int i = 0; i < n; i++) {
            ps.assign(k + 1, 0);
            for (int s = 0; s < k; s++) {
                ps[s + 1] = (ps[s] + dp[s]) % MOD;
            }
            for (int s = 0; s < k; s++) {
                int low = max(0, s - buckets[i]);
                ndp[s] = (ps[s] - ps[low] + MOD) % MOD;
            }
            swap(dp, ndp);
            ndp.assign(k, 0);
        }
        ll bad = 0;
        for (int s = n; s < k; s++) {
            bad = (bad + dp[s]) % MOD;
        }
        ll ans = (tot - bad + MOD) % MOD;
        return ans;
    }
};
