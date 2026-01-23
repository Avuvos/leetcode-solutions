class Solution {
public:
    long long minimumCost(string s, string t, int flipCost, int swapCost, int crossCost) {
        /* s[i] = t[i] -> continue
        Separate to cases, we can always flipCost, or swap + cross or sometimes one swap is enough.
        */
        int n = s.size(), d = 0;
        int zeros = 0, ones = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == t[i]) continue;
            d++;
            if (s[i] == '0') {
                zeros++;
            } else {
                ones++;
            }
        }
        long long ans = 0;
        int mn = min(ones, zeros);
        d -= 2 * mn;
        ans += 1LL * mn * min(2 * flipCost, swapCost);
        if (d % 2 == 1) {
            ans += 1LL * flipCost;
            d--;
        }
        ans += 1LL * (d / 2) * min(2 * flipCost, swapCost + crossCost);
        return ans;
    }
};
