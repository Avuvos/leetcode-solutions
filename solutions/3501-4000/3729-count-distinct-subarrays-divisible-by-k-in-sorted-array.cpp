class Solution {
public:
    long long numGoodSubarrays(vector<int>& nums, int k) {
        long long s = 0, res = 0;
        map<long long, long long> groups;
        unordered_map<long long, long long> mp;
        mp[0]++;
        for (auto &x: nums) {
            groups[x]++;
        }

        for (auto [key, val]: groups) {
            // Connect the current group to other groups
            long long cur = s;
            mp[s]--;
            for (int i = 0; i < val; i++) {
                cur = (cur + key) % k;
                res += mp[cur % k];
            }
            mp[s]++;

            // Individually count the groups contribution
            cur = 0;
            for (int i = 0; i < val; i++) {
                cur = (cur + key) % k;
                if (cur % k == 0) {
                    res++;
                }
                mp[(s + cur) % k]++;
            }
            s = (s + cur) % k;
        } 

        return res;
    }
};
