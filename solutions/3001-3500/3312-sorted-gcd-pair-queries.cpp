class Solution {
public:
    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {
        int mx = *max_element(nums.begin(), nums.end());
        vector<int> cnt_divs(mx + 1, 0);
        for (auto &x: nums) {
            for (int d = 1; d * d <= x; d++) {
                if (x % d == 0) {
                    cnt_divs[d]++;
                    if (x / d != d) {
                        cnt_divs[x / d]++;
                    }
                }
            }
        }
        
        vector<long long> cnt_gcd(mx + 1, 0);
        for (int d = mx; d >= 0; d--) {
            if (cnt_divs[d] <= 1) continue;
            cnt_gcd[d] = 1LL * cnt_divs[d] * (cnt_divs[d] - 1) / 2;
            for (int mult = 2 * d; mult <= mx; mult += d) {
                cnt_gcd[d] -= cnt_gcd[mult];
            }
        }
        
        vector<long long> ps(mx + 1, 0);
        for (int i = 1; i <= mx; i++) {
            ps[i] = ps[i - 1] + cnt_gcd[i];
        }
        
        
        int q = queries.size();
        vector<int> ans(q);
        for (int i = 0; i < q; i++) {
            ans[i] = lower_bound(ps.begin(), ps.end(), queries[i] + 1) - ps.begin();
        }
        return ans;
    }
};
