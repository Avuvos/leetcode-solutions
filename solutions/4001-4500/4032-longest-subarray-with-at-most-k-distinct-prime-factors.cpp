class Solution {
public:
    int longestSubarray(vector<int>& nums, int k) {
        unordered_map<int, unordered_set<int>> mp;
        for (auto& x: nums) {
            if (mp.contains(x)) continue;
            int y = x;
            for (int i = 2; i * i <= x; i++) {
                if (y % i == 0) {
                    mp[x].insert(i);
                    while (y > 0 && y % i == 0) {
                        y /= i;
                    }
                }
            }
            if (y > 1) {
                mp[x].insert(y);
            }
        }
        int ans = 0;
        unordered_map<int, int> window;
        for (int r = 0, l = 0; r < nums.size(); r++) {
            for (auto &p: mp[nums[r]]) {
                window[p]++;
            }
            while (l <= r && window.size() > k) {
                for (auto &p: mp[nums[l]]) {
                    if (--window[p] == 0) {
                        window.erase(p);
                    }
                }
                l++;
            }
            if (window.size() <= k) {
                ans = max(ans, r - l + 1);
            }
        }
        return ans;
    }
};
