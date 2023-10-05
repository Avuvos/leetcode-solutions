class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = (int) nums.size();
        map<int, int> mp;
        vector<int> ans;
        for (auto &x: nums) {
            if (++mp[x] > n/3) {
                ans.push_back(x);
            }
        }

        sort(ans.begin(), ans.end());
        ans.resize(unique(ans.begin(), ans.end()) - ans.begin());
        return ans;
    }
};
