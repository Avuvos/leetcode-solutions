class Solution {
public:
    vector<int> findXSum(vector<int>& nums, int k, int x) {
        int n = nums.size();
        vector<int> ans(n - k + 1);
        for (int i = 0; i < n - k + 1; i++) {
            map<int, int> mp;
            for (int j = i; j < i + k; j++) {
                mp[nums[j]]++;
            }
            vector<pair<int, int>> v;
            for (auto &[key, val]: mp) {
                v.push_back({val, key});
            }
            sort(v.begin(), v.end(), [&](const pair<int, int> &p1, const pair<int, int> &p2) {
                return p1.first != p2.first ? p1.first > p2.first : p1.second > p2.second;
            });
            int res = 0;
            for (int j = 0; j < min(x, (int) v.size()); j++) {
                res += v[j].first * v[j].second;
            }
            ans[i] = res;
        }
        return ans;
    }
};
