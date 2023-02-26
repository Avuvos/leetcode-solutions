class Solution {
public:
    int maxNumOfMarkedIndices(vector<int>& nums) {
        int n = (int) nums.size();
        sort(nums.begin(), nums.end());
        int l = 0, r = n/2;
        vector<bool> marked(n, false);
        int ans = 0;
        while (r < n && l < n/2 && !marked[l]){ //maybe <=
            if (nums[l] *2 <= nums[r] && !marked[r]) {
                marked[l] = true;
                marked[r] = true;
                ans += 2;
                l++;
            } else {
                r++;
            }
        }
        return ans;
        
    }
};
