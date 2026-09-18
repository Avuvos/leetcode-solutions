class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        unordered_map<int, vector<int>> mp;
        for (int i = 0; i < nums.size(); i++) {
            mp[nums[i]].push_back(i);
        }
        int ans = 0;
        for (auto &[x, pos]: mp) {
            bool ok = true;
            for (int i = 0; i + 1 < pos.size(); i++) {
                if (pos[i + 1] - pos[i] != 1) {
                    ok = false;
                    break;
                }
            }
            ans += ok;
        }
        return ans;
    }
};
