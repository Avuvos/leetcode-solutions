class Solution {
public:
    int kk;
    int dfs(int index, vector<int>& nums, vector<int>& cnt) {
        if (index >= nums.size()) return 1;
        int take = 0, skip = 0;
        if (cnt[nums[index] + kk] == 0) {
            cnt[nums[index]]++;
            take = dfs(index + 1, nums, cnt);
            cnt[nums[index]]--;
        }
        skip = dfs(index + 1, nums, cnt);
        return take + skip;
    }
    
    int beautifulSubsets(vector<int>& nums, int k) {
        int n = (int) nums.size();
        sort(nums.rbegin(), nums.rend());
        int ans = 0;
        kk = k;
        vector<int> cnt(2005, 0);
        // for (int mask = 1; mask < (1 << n); mask++) {
        //      bool ok = true;
        //      for (int i = 0; i < n; i++) {
        //          if ((mask >> i) & 1) {
        //              if (cnt[nums[i] + k] > 0) {
        //                  ok = false;
        //              }
        //              cnt[nums[i]]++;
        //          }
        //      }
        //      ans += ok;
        //         for (int i = 0; i < n; i++) {
        //          if ((mask >> i) & 1) {
        //              cnt[nums[i]]--;
        //          }
        //      }
        // }
        // return ans;
        return dfs(0, nums, cnt) - 1;
    }
};
