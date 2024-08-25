class Solution {
public:
    
    long long expo(long long a, long long b, int mod) {
        long long res = 1;
        while (b > 0) {
            if (b & 1) {
                res *= a;
                res %= mod;
            }
            a *= a;
            a %= mod;
            b >>= 1;
        }
        return res;
    }
    
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        if (multiplier == 1) {
            return nums;
        }
        const int MOD = 1e9 + 7;
        int n = (int) nums.size();
        long long mx = *max_element(nums.begin(), nums.end());
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> pq;
        for (int i = 0; i < n; i++) {
            pq.push({nums[i], i});
        }
        while (k--) {
            auto [mn, idx] = pq.top(); pq.pop();
            long long nxt = mn * multiplier;
            pq.push({nxt, idx});
            
            if (nxt > mx) {
                break;
            }
            mx = max(mx, nxt);
        }
        int q = k / n;
        int r = k % n;
        while (!pq.empty()) {
            auto [cur, idx] = pq.top(); pq.pop();
            cur %= MOD;
            cur *= expo(multiplier, q + (r > 0), MOD);
            cur %= MOD;
            r--;
            nums[idx] = cur;
        }
        return nums;
    }
};
