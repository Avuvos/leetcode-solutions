class Solution {
public:
    int maxCapacity(vector<int>& costs, vector<int>& capacity, int budget) {
        int n = costs.size(), ans = 0;
        
        vector<int> order(n);
        iota(order.begin(), order.end(), 0);
        sort(order.begin(), order.end(), [&](int i, int j) {
            return costs[i] < costs[j];
        });

        vector<pair<int, int>> stk;
        for (auto &idx: order) {
            int cost = costs[idx], cap = capacity[idx];

            if (cost >= budget) continue;
            ans = max(ans, cap);

            // search in the stk for the largest value such that its <= budget - cost, take it's cap.
            auto it = lower_bound(stk.begin(), stk.end(), pair<int, int>{budget - cost, -1});
            if (it != stk.begin()) {
                it--;
                ans = max(ans, it -> second + cap);
            }

            if (stk.empty() || stk.back().second < cap) {
                stk.push_back({cost, cap});
            }
        }
        return ans;
    }
};
