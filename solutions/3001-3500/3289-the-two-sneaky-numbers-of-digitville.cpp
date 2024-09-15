class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        vector<int> cnt(101, 0);
        vector<int> ans;
        for (auto &x: nums) {
            if (++cnt[x] == 2) {
                ans.push_back(x);
            }
        }
        return ans;
    }
};
