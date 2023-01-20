class Solution {
public:
    vector<vector<int>> all;
    vector<int> nums;
    void dfs(int index, vector<int>& cur) {
        if (index >= nums.size()) {
            bool ok = true;
            for (int i = 0; i + 1 < cur.size(); i++) {
                if (cur[i] > cur[i + 1]) ok = false;
            }
            if (ok && cur.size() >= 2) {
                all.push_back(cur);
            }
            return;
        }
        dfs(index + 1, cur);
        cur.push_back(nums[index]);
        dfs(index + 1, cur);
        cur.pop_back();
        
    }
    
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        this -> nums = nums;
        vector<int> cur;
        dfs(0, cur);
        vector<vector<int>> ans;
        sort(all.begin(), all.end());
        vector<int> prev;
        for (int i = 0; i < all.size(); i++) {
            bool ok = prev.size() != all[i].size();
            if (ok) {
                ans.push_back(all[i]);
                prev = all[i];
                continue;
            }
            
            for (int j = 0; j < all[i].size(); j++) {
                if (all[i][j] != prev[j]) {
                    ok = true;
                    break;
                }
            }
            if (ok) {
                ans.push_back(all[i]);
                prev = all[i];
                continue;
            }
            
        }
        
        return ans;
    }
};
