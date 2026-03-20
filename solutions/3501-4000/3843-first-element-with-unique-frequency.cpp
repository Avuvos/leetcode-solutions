class Solution {
public:
    int firstUniqueFreq(vector<int>& nums) {
        unordered_map<int, int> mp;
        for (auto &x: nums) {
            mp[x]++;
        }
        unordered_map<int, int> freqs;
        for (auto &[_, v]: mp) {
            freqs[v]++;
        }
        for (auto &x: nums) {
            if (freqs[mp[x]] == 1) {
                return x;
            }
        }
        return -1;
    }
};
