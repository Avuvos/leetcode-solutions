class Solution {
public:
    long long beautifulSubarrays(vector<int>& nums) {
        long long ans = 0;
        map<int, int> state_to_cnt;
        state_to_cnt[0] = 1;
        int mask = 0;
        for (int i = 0; i < nums.size(); ++i) {
            mask ^= nums[i];
            ans += state_to_cnt[mask];
            state_to_cnt[mask]++;
        }
        return ans;
    }
};
