class Solution {
public:
    vector<long long> mostFrequentIDs(vector<int>& nums, vector<int>& freq) {
        int n = (int) nums.size();
        map<long long, long long> mp;
        vector<long long> ans(n);
        set<pair<long long, long long>> s;
        for (int i = 0; i < n; i++) {
            s.erase({mp[nums[i]], nums[i]});
            mp[nums[i]] += freq[i];
            s.insert({mp[nums[i]], nums[i]});
            ans[i] = s.empty() ? 0 : s.rbegin() -> first;
        }
        return ans;
    }
};
