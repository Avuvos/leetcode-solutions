class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        unordered_map<int, vector<int>> mp;
        for (int i = 0; i < nums.size(); i++) {
            mp[nums[i]].push_back(i);
        }
        int ans = 0;
        for (auto &[key, val]: mp) {
            if (val.size() < 3) continue;
            bool ok = true;
            int d0 = val[1] - val[0];
            for (int i = 2; i < val.size(); i++) {
                if (val[i] - val[i - 1] != d0) {
                    ok = false;
                    break;
                }
            }
            ans += ok;
        }
        return ans;
    }
};
