class Solution {
public:
    long long maxRatings(vector<vector<int>>& units) {
        int m = units.size(), n = units[0].size();
        if (n == 1) {
            return accumulate(units.begin(), units.end(), 0LL, [](long long sum, auto& cap) {
                return sum + cap[0];
            });
        }

        int mn = 1e9 + 2, sec_mn = 1e9 + 2;
        long long ans = 0;
        for (auto &cap: units) {
            sort(cap.begin(), cap.end());
            mn = min(mn, cap[0]);
            sec_mn = min(sec_mn, cap[1]);
            ans += cap[1];
        }
        ans -= sec_mn;
        ans += mn;
        return ans;
    }
};
