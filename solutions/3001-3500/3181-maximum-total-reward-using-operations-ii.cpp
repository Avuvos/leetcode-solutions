class Solution {
public:
    int maxTotalReward(vector<int>& a) {
        sort(a.begin(), a.end());
        a.resize(unique(a.begin(), a.end()) - a.begin());
        int n = (int) a.size();
        const int N = 100001;
        bitset<N> dp;
        dp[0] = 1;
        for (int i = 0; i < n; i++) {
            int shift = N - 1 - (a[i] - 1);
            dp = dp | (dp << shift >> shift << a[i]);
        }
        int ans = N - 1;
        while (!dp[ans]) {
            ans--;
        }
        return ans;
        
        
    }
};
