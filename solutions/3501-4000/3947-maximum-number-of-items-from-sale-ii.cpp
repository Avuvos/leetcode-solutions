class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n = items.size(), low = 1e9;
        vector<int> freq(n + 1, 0);
        for (auto &i: items) {
            freq[i[0]]++;
            low = min(low, i[1]);
        }

        vector<int> value(n + 1, -1);
        for (int i = 1; i <= n; i++) {
            for (int j = i; j <= n; j += i) {
                value[i] += freq[j];
            }
        }

        vector<tuple<double, int, int>> order;
        for (auto &i: items) {
            order.push_back({2.0 / i[1] , -i[1] , value[i[0]]});
        }
        sort(order.rbegin(), order.rend());

        int ans = 0;
        for (auto &[r, p, c]: order) {
            p *= -1;
            if (p > budget || r < 1.0 / low) break;
            int cnt = min(budget / p, c);
            ans += cnt * 2;
            budget -= p * cnt;
        }
        ans += budget / low;
        return ans;
    }
};
