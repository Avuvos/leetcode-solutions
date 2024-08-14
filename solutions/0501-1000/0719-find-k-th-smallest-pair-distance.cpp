class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        int n = (int) nums.size();
        sort(nums.begin(), nums.end());
        
        //count the number of pairs with distance <= x
        auto count_pairs = [&](int x) -> int {
            int cnt = 0;
            for (int r = 0, l = 0; r < n; r++) {
                while (nums[r] - nums[l] > x) {
                    l++;
                }
                cnt += r - l;
            }
            return cnt;
        };
        
        int left = 0, right = 3e6, ans = 0;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (count_pairs(mid) >= k) {
                ans = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return ans;
    }
};
