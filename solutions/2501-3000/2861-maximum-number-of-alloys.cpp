class Solution {
public:
    typedef long long ll;
    int maxNumberOfAlloys(int n, int k, int budget, vector<vector<int>>& composition, vector<int>& stock, vector<int>& cost) {
        ll ans = 0;
        
        auto canMake = [&](int index, ll amount) {
            long long pay = 0;
            for (int i = 0; i < n; i++) {
                int metal = composition[index][i];
                ll need = amount * metal;
                need -= stock[i];
                if (need <= 0) continue;
                pay += cost[i] * need;
            };
            return pay <= budget;
        };
        
        for (int i = 0; i < k; i++) {
            ll left = 0, right = 1e9, cur = 1e9;
            while (left <= right) {
                ll mid = left + (right - left)/2;
                if (canMake(i, mid)) {
                    cur = mid;
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            }
            ans = max(ans, cur);
        }
        return ans;
    }
};
