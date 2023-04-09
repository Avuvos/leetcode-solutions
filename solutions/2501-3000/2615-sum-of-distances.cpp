class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        int n = (int)nums.size();
        vector<long long> ans(n, 0);
        unordered_map<int, vector<int>> mp;
        unordered_map<int, vector<long long>> ps;
        for (int i = 0; i < n; i++) {
            int x = nums[i];
            if (ps.find(x) == ps.end()) ps[x].push_back(0);
            mp[x].push_back(i);
            ps[x].push_back(ps[x].back() + i);
        }
        
        // for (auto &[key, val]: mp) {
        //     vector<long long> pr;
        //     pr.push_back(0);
        //     for (auto &idx: val) {
        //         pr.push_back(pr.back() + idx);
        //     }
        //     ps[key] = pr;
        // }
        
        for (long long i = 0; i < n; i++) {
            int x = nums[i];
            int index = lower_bound(mp[x].begin(), mp[x].end(), i) - mp[x].begin();
            long long m = (long long) mp[x].size();
            if (index == m) {
                ans[i] = m*i - ps[x][m];
            } else if (index == 0) {
                 ans[i] = ps[x][m] - m*i;
            } else {
                long long left = index*i - ps[x][index];
                long long right = (ps[x][m]-ps[x][index]) - (m-index)*i;
                ans[i] = left + right;
            }
        }
        return ans;
    }
};
