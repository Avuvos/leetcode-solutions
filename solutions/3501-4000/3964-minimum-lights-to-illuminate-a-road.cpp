class Solution {
public:
    int minLights(vector<int>& lights) {
        int n = lights.size();
        vector<int> cov(n + 1, 0);
        for (int i = 0; i < n; i++) {
            int v = lights[i];
            if (v == 0) continue;
            int l = max(0, i - v), r = min(n - 1, i + v);
            cov[l]++;
            cov[r + 1]--;
        }
        for (int i = 0; i < n; i++) {
            cov[i + 1] += cov[i];
        }
        int st = 0, ans = 0;
        for (int i = 0; i < n; i++) {
            if (cov[i] > 0) {
                ans += (st + 2) / 3;
                st = 0;
            } else {
                st++;
            }
        }
        ans += (st + 2) / 3;
        return ans;
    }
};
