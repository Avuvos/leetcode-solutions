class Solution {
public:
    int singleNumber(vector<int>& nums) {
        map<int, int> mp;
        for (auto &a: nums) mp[a]++;
        for (auto &[key, val]: mp) if (val == 1) return key;
        return -1;
    }
};
