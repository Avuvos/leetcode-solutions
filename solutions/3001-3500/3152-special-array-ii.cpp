class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        int n = (int) nums.size();
        vector<int> ps(n, 0);
        for (int i = 0; i + 1 < n; i++) {
            ps[i + 1] = ps[i] + (nums[i] % 2 == nums[i + 1] % 2);
        }
        
        vector<bool> ans;
        for (auto &q: queries) {
            int l = q[0], r = q[1];
            ans.push_back(ps[r] - ps[l] == 0);
        }
        return ans;
        
    }
};
