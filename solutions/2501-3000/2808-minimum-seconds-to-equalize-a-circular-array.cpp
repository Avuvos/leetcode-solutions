class Solution {
public:
    int minimumSeconds(vector<int>& nums) {
        map<int, vector<int>> mp;
        int n = (int) nums.size();
        for (int i = 0; i < n; i++) {
            mp[nums[i]].push_back(i);
        }
        // cout << "new case" << endl;
        int ans = 1e9;
        for (auto [k, v]: mp) {
            int max_diff = 0, m = (int) v.size();
            for (int i = 0; i < m; i++) {
                if (i < m - 1) {
                    max_diff = max(max_diff, (v[i + 1] - v[i] - 1 + 2 - 1)/2);
                } else {
                    int db = n - 1 - v[i];
                    int df = v[0];
                    max_diff = max(max_diff, (db + df + 1)/2);
                }
            }
            // cout << k << " " << max_diff << endl;
            ans = min(ans, max_diff);
        }
        return ans;
    }
};
