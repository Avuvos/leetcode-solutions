class Solution {
public:
    double minPrice(vector<int>& prices, vector<int>& discounts) {
        int n = prices.size(), m = discounts.size();
        sort(prices.rbegin(), prices.rend());
        sort(discounts.rbegin(), discounts.rend());
        int i = 0, j = 0;
        double ans = 0;
        for (int i = 0; i < n; i++) {
            double d = 0;
            if (j < m) {
                d = discounts[j++];
            }
            ans += 1.0 * prices[i] * (100 - d) / 100.0;
        }
        return ans;
    }
};

