class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        int cnt[101] = {};
        int ans = 0;
        for (auto &x: nums) {
            ans += cnt[x]++;
        }
        return ans;
    }
};
