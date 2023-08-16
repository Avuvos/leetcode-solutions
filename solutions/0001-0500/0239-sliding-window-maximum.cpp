class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        set<pair<int, int>> s;
        vector<int> ans;
        for (int i = 0; i < nums.size(); i++) {
            s.insert(make_pair(nums[i], i));
            if (i - k >= 0) {
                s.erase(make_pair(nums[i - k], i - k));
            }
            if ((int) s.size() == k) {
                ans.push_back(s.rbegin() -> first);
            }
            
            if (i > k && s.size() < k) {
                break;
            }
            
        }
        return ans;
    }
};
