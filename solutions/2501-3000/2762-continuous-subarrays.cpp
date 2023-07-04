class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        int n = (int) nums.size();
        set<pair<int, int>> set_max;
        set<pair<int, int>> set_min;
        long long ans = 0;
        for (int right = 0, left = 0; right < n; right++) {
            set_max.insert(make_pair(-nums[right], right));
            set_min.insert(make_pair(nums[right], right));
            while (-set_max.begin()->first - set_min.begin()->first > 2) {
                set_max.erase(make_pair(-nums[left], left));
                set_min.erase(make_pair(nums[left], left));
                left++;
            }
            ans += (right - left + 1);
        }
        return ans;
    }
};
