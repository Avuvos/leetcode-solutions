class Solution {
public:
    long long minimumCost(vector<int>& nums) {
        long long ans = 1e18, med = 0;
        int n = (int) nums.size();
        sort(nums.begin(), nums.end());
        med = nums[n / 2];
        vector<int> cand;
        auto pal = [&](int x) {
            string s = to_string(x);
            int l = 0, r = s.size() - 1;
            while (l <= r) {
                if (s[l] != s[r]) {
                    return false;
                }
                l++;
                r--;
            }
            return true;
        };
        
        int b = 10000;
        for (int i = med; i <= min(med + b, (long long)1e9); i++) {
            if (pal(i)) {
                cand.push_back(i);
            }
        }
        for (int i = med - 1; i > max(med - b, 0LL); i--) {
            if (pal(i)) {
                cand.push_back(i);
            }
        }
        
        for (auto &x: cand) {
            long long cur = 0;
            for (int i = 0; i < n; i++) {
                cur += abs(nums[i] - x);
            }
            ans = min(ans, cur);
        }
        return ans;
    }
};
