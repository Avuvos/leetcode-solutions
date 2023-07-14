class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        map<int, int> mp;
        for (int i = 0; i < arr.size(); i++) {
            mp[arr[i]] = max(mp[arr[i]], 1 + mp[arr[i] - difference]);
        }
        int ans = 0;
        for (auto [key, val]: mp) {
            ans = max(ans, val);
        }
        return ans;
    }
};
