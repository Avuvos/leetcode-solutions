class Solution {
public:
    long long countStableSubarrays(vector<int>& capacity) {
        map<pair<int, long long>, int> mp;
        long long s = 0, res = 0;
        pair<int, long long> prev = {1e9 + 1, 0};
        for (auto &x: capacity) {
            res += mp[{x, s - x}];
            s += x;
            mp[prev]++;
            prev = {x, s};
        }
        return res;
    }
};
