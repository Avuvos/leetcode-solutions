class Solution {
public:
    vector<int> relocateMarbles(vector<int>& nums, vector<int>& moveFrom, vector<int>& moveTo) {
        map<int, long long> mp;
        for (int x: nums) {
            mp[x]++;
        }
        for (int i = 0; i < moveFrom.size(); i++) {
            int start = moveFrom[i], end = moveTo[i];
            if (start == end) continue;
            mp[end] += mp[start];
            mp[start] = 0;
        }
        vector<int> ans;
        for (auto [key, val]: mp) {
            if (val > 0) ans.push_back(key);
        }
        
        return ans;
    }
};
