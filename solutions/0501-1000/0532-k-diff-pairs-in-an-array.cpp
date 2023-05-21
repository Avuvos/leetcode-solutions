class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        int prevSize = (int) nums.size();
        if (k == 0) {
            map<int, int> cnt;
            for (auto &a: nums) cnt[a]++;
            int res = 0;
            for (auto [key, val]: cnt) if (val >= 2) res++;
            return res;
        }
        sort(nums.begin(), nums.end());
        nums.erase(unique(nums.begin(), nums.end()), nums.end());
        int n = (int) nums.size();
        
        long long ans = 0;
        for (int i = 0; i < n; i++) {
            int index = lower_bound(nums.begin() + i + 1, nums.end(), nums[i] + k) - nums.begin();
            if (index == n || nums[index] - nums[i] != k) continue;
            ans += 1;
        }
        return ans;
    }
};
