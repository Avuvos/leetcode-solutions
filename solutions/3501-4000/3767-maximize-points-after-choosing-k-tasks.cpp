class Solution {
public:
    long long maxPoints(vector<int>& t1, vector<int>& t2, int k) {
        int n = t1.size(), t = 0;
        long long ans = 0;
        vector<pair<int, int>> d;
        for (int i = 0; i < n; i++) {
            if (t1[i] >= t2[i]) {
                t++;
                ans += t1[i];
                continue;
            }
            d.push_back({t2[i] - t1[i], i});
        }
        sort(d.begin(), d.end());
        for (auto [v, i]: d) {
            if (t < k) {
                t++;
                ans += t1[i];
            } else {
                ans += t2[i];
            }
        }
        return ans;
    }
};
