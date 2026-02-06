class Solution {
public:
    long long minCost(string s, vector<int>& cost) {
        int n = cost.size();
        long long sum = accumulate(cost.begin(), cost.end(), 0LL);
        vector<long long> cost_per_ch(26, 0);
        for (int i = 0; i < n; i++) {
            cost_per_ch[s[i] - 'a'] += cost[i];
        }
        long long ans = 1e17 + 2;
        for (int i = 0; i < 26; i++) {
            ans = min(ans, sum - cost_per_ch[i]);
        }
        return ans;
    }
};
