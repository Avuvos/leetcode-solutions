class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        unordered_map<int, vector<int>> mp;
        for (int i = 0; i < nums.size(); i++) {
            mp[nums[i]].push_back(i);
        }
        int ans = 0;
        for (auto &[key, val]: mp) {
            if (val.size() != 3) continue;
            ans += (val[1] - val[0] == val[2] - val[1]);
        }
        return ans;
    }
};
