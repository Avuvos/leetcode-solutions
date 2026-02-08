class Solution {
public:
    int maximumSum(vector<int>& nums) {
        // {section of mod 0 (only top 3 interesting)}
        // {section of mod 1}
        // {section of mod 2}
        // 0,0,0, 0,1,2, 1,1,1, 2,2,2
        // so we care about top 3 from each modulo.
        vector<vector<int>> a(3);
        for (auto &x: nums) {
            a[x % 3].push_back(x);
        }
        for (auto &v: a) {
            sort(v.rbegin(), v.rend());
        }
        int ans = 0;
        for (int i = 0; i < 3; i++) {
            if (a[i].size() >= 3) {
                ans = max(ans, a[i][0] + a[i][1] + a[i][2]);
            }
        }
        if (a[0].size() > 0 && a[1].size() > 0 && a[2].size() > 0) {
            ans = max(ans, a[0][0] + a[1][0] + a[2][0]);
        }
        return ans;
    }
};
