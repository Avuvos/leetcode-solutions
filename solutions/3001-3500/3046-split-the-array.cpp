class Solution {
public:
    bool isPossibleToSplit(vector<int>& nums) {
        map<int, int> mp;
        for (auto &x: nums) {
            if (++mp[x] >= 3) {
                return false;
            }
        }
        return true;
    }
};
