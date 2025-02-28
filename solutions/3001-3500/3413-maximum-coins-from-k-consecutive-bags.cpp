class Solution {
public:
    long long maximumCoins(vector<vector<int>>& coins, int k) {
        /*  
        Sort coins
        Suppose we choose some xi to start with, then we collect [xi, xi + k]
        We can binary search for the index of the coin where xi+k is in [lj, rj].
        Then collect the values using prefix sums
        I think we can prove that in an optimal solution, we always take one of the edges of some coin,
        either backward or forward.
        Suppose not, it means we can always shift one left or shift one right to the larger one of the intervals,
        and at best not decrease our score.
        So it's enough to check forward from every li, and backwards from every ri.
        */
        long long ans = 0;
        int n = coins.size();
        sort(coins.begin(), coins.end());
        
        vector<long long> ps(n + 1, 0);
        for (int i = 0; i < n; i++) {
            ps[i + 1] = ps[i] + 1LL * (coins[i][1] - coins[i][0] + 1) * coins[i][2];
        }
        
        auto get = [&](int i) -> long long {
            long long score_forward = 0, score_backward = 0;
            // case 1
            int left = coins[i][0], right = left + k - 1;
            // cout << "left " << left << " " << "right" << " " << right << endl;
            
            // Searching for latest interval that contains right
            int l = i, r = n - 1, idx = i;
            while (l <= r) {
                int m = l + (r - l) / 2;
                if ((right >= coins[m][0] && right <= coins[m][1]) || (right >= coins[m][1])) {
                    idx = m;
                    l = m + 1;
                } else {
                    r = m - 1;
                }
            }
            // cout << "idx found is" << idx << endl;
            
            if (right >= coins[idx][1]) {
                score_forward = ps[idx + 1] - ps[i];
                // cout << "op1 " << score_forward << endl;
            } else {
                int prev_idx = idx - 1;
                if (prev_idx >= i) {
                    score_forward = ps[prev_idx + 1] - ps[i];
                }
                score_forward += 1LL * (right - coins[idx][0] + 1) * coins[idx][2];
                // cout << "op2 " << score_forward << endl;
            }
            
            
            // case 2
            // Searching for earliest interval that contains left
            right = coins[i][1], left = right - k + 1;
            
            // cout << "left " << left << " " << "right" << " " << right << endl;
            l = 0, r = i, idx = i;
            while (l <= r) {
                int m = l + (r - l) / 2;
                if ((left >= coins[m][0] && left <= coins[m][1]) || left <= coins[m][0]) {
                    idx = m;
                    r = m - 1;
                } else {
                    l = m + 1;
                }
            }
            
            // cout << "idx found is" << idx << endl;
            
            if (left <= coins[idx][0]) {
                score_backward = ps[i + 1] - ps[idx];
                // cout << "op1 " << score_forward << endl;
            } else {
                int prev_idx = idx + 1;
                if (prev_idx <= i) {
                    score_backward = ps[i + 1] - ps[prev_idx];
                }
                score_backward += 1LL * (coins[idx][1] - left + 1) * coins[idx][2]; 
                // cout << "op2 " << score_backward << endl;
            }
            
            // cout << i << " " << score_forward << " " << score_backward << endl;
            
            return max(score_forward, score_backward);
        };
        
        for (int i = 0; i < n; i++) {
            ans = max(ans, get(i));
        }
        
        
        return ans;
        
        
    }
};
