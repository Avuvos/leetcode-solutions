/* 
dp_low dp_high, dp_low[i] max subarray ends at i with at most one removal where a[i] < last ele
dp_high[i] same idea but a[i] > last ele
so we use dp_low to calc dp_high and viceversa.
also compute two other arrays dp_alt_high, max subarray that ends at i alternating with NO removals.
and then we can use that to compute our dp, since at element i, we can skip i - 1,
and take i - 2. we cannot do that more than once.
so our dp_low is either connect straight to the dp_high[i - 1] given ai < last ele
and for dp_high its dp_low[i -1] given ai > last ele.. 
or skip i - 1, and take dp_alt_low[i - 2] or dp_alt_high[i - 2];
*/
class Solution {
public:
    int longestAlternating(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp_low(n, 1), dp_high(n, 1);
        vector<int> dp_alt_low(n, 1), dp_alt_high(n, 1);
        for (int i = 1; i < n; i++) {
            // No delete
            if (nums[i] > nums[i - 1]) {
                dp_high[i] = 1 + dp_low[i - 1];
                dp_alt_high[i] = 1 + dp_alt_low[i - 1];
            } else if (nums[i] < nums[i - 1]) {
                dp_low[i] = 1 + dp_high[i - 1];
                dp_alt_low[i] = 1 + dp_alt_high[i - 1];
            }

            if (i < 2) continue;

            // Delete
            if (nums[i] > nums[i - 2]) {
                dp_high[i] = max(dp_high[i], 1 + dp_alt_low[i - 2]);
            } else if (nums[i] < nums[i - 2]) {
                dp_low[i] = max(dp_low[i], 1 + dp_alt_high[i - 2]);
            }
        }
        int max_low = *max_element(dp_low.begin(), dp_low.end());
        int max_high = *max_element(dp_high.begin(), dp_high.end());
        return max(max_low, max_high);
    }
};
