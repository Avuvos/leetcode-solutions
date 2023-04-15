class Solution {
public:
    typedef long long ll;
    vector<long long> findPrefixScore(vector<int>& nums) {
        vector<ll> ans;
        vector<ll> conv;
        ll mx = 0, sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            mx = max((ll)nums[i], mx);
            conv.push_back(nums[i] + mx);
            sum += conv.back();
            ans.push_back(sum);
        }
        return ans;
    }
};
