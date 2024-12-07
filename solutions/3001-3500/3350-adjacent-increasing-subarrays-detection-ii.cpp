class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& len, int k) {
        int n = len.size();
        for (int i = 1; i < n; i++) {
            if (len[i - 1] >= k && i + k - 1 < n && len[i + k - 1] >= k) {
                return true;
            }
        }
        return false;
    }
    
    int maxIncreasingSubarrays(vector<int>& nums) {
        int n = nums.size();
        vector<int> len(n, 1);
        for (int i = 1; i < n; i++) {
            if (nums[i] > nums[i - 1]) {
                len[i] += len[i - 1];
            }
        }
        int left = 2, right = (n + 1) / 2, ans = 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (hasIncreasingSubarrays(len, mid)) {
                ans = mid;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return ans;
        
    }
};
