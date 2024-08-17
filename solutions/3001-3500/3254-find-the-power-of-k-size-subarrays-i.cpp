class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> ok(n, 1);
        for (int i = 1; i < n; i++) {
            ok[i] = (nums[i] == nums[i - 1] + 1);
        }
        int val = 0;
        vector<int> res;
        for (int l = 0, r = 0; r < n; r++) {
            val += ok[r];
            if (r - l + 1 > k) {
                val -= ok[l];
                l++;
            }
            if (r - l + 1 == k) {
                res.push_back(val - ok[l] == k - 1 ? nums[r] : -1);
            }
        }
        return res;
        
    }
};
