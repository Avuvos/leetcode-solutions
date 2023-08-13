class Solution {
public:
    int minAbsoluteDifference(vector<int>& nums, int x) {
        //all we care about is the max/min on the suffix.
        set<pair<int, int>> s;
        int n = (int) nums.size();
        long long ans = abs(nums.back() - nums[0]);
        for (int i = x; i < n; i++) {
            s.insert(make_pair(nums[i], i));
        }
        
        for (int i = 0; i < n && !s.empty(); i++) {
            long long cur = nums[i];
            auto it = s.lower_bound(make_pair(cur, i));
            ans = min(ans, abs(cur - it -> first));
            if (it != s.begin()) {
                it = prev(it);
                ans = min(ans, abs(cur - it -> first));
            }
            if (i + x < n) {
                s.erase(make_pair(nums[i + x], i + x));
            }
        }
        
        return ans;
        
    }
};
