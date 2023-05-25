class Solution {
public:
    double new21Game(int n, int k, int maxPts) {
        if (n < k) return 0;
        if (k == 0) return 1;
        
        double p = 1.0/maxPts;
        
        vector<double> dp(n + 1, 0);
        for (int i = k; i <= n; i++) {
            dp[i] = 1.0;
        }
        
        int right = k - 1;
        double sum = 0; //sub from the sum dp[right]?
        // for (int i = k - 1; i >= 0; i--) {
        //     for (int pt = 1; pt <= maxPts && i + pt <= n; pt++) {
        //         dp[i] += p * dp[i + pt];
        //     }
        // }
        
        for (int pt = 1; pt <= maxPts && k - 1 + pt <= n; pt++) {
            sum += dp[k - 1 + pt];
            right = k - 1 + pt;
            dp[k - 1] += dp[k - 1 + pt];
        }
        dp[k - 1] *= p;
        for (int i = k - 2; i >= 0; i--) {
            if (i + maxPts < right) {
                sum -= dp[right];
                right--;
            }
            sum += dp[i + 1];
            dp[i] = sum * p;
        }
        return dp[0];
        
    }
};
