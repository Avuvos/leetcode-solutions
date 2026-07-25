class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        // buy each item at most once
        // then in the end spend all the remaining budget on the cheapest item to get as many copies as possible
        // assume we get k copies from buying one item x
        // then its worth to buy x if price(x) < minPrice * k 
        // otherwise just buy k copies of the lowest item and it's better.
        // then its just a knapsack problem i think... solved via dp.
        int n = items.size(), low = 1e9;
        for (auto &i: items) {
            low = min(low, i[1]);
        }
        if (low > budget) return 0;
        vector<pair<int, int>> values(n);
        for (int i = 0; i < n; i++) {
            if (items[i][1] > budget) {
                values[i] = {items[i][1], 0};
                continue;
            }
            int cnt = 1;
            for (int j = 0; j < n; j++) {
                if (i != j && items[j][0] % items[i][0] == 0) {
                    cnt++;
                }
            }
            values[i] = {items[i][1], cnt};
        }
        sort(values.begin(), values.end());
        vector<int> dp(budget + 1, 0);
        for (auto &[cost, value]: values) {
            for (int i = budget; i >= 0; i--) {
                if (i - cost >= 0) {
                    dp[i] = max(dp[i], value + dp[i - cost]);
                }
            }
        }
        int ans = 0;
        for (int i = budget; i >= 0; i--) {
            ans = max(ans, dp[i] + (budget - i) / low);
        }
        return ans;
    }
};
