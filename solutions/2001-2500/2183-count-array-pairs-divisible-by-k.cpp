class Solution {
public:
    long long countPairs(vector<int>& nums, int k) {
        unordered_map<long long, long long> mp;
        for (auto &num: nums) mp[gcd(num, k)]++;
        long long ans = 0;
        for (auto &[v1, c1]: mp) {
            for (auto &[v2, c2]: mp) {
                if (v1 > v2 || v1*v2 % k != 0) continue;
                if (v1 == v2) {
                    ans += c1*(c1 - 1)/2;
                } else {
                    ans += c1*c2;
                }
            }
        }
        return ans;
    }
};
