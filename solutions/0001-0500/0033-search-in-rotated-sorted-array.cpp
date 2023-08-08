class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        int INF = 1e9;
        
        while (left <= right) {
            int mid = left + (right - left)/2;
            int current;
            if ((nums[mid] < nums[0] && target < nums[0]) ||
                (nums[mid] >= nums[0] && target >= nums[0])) {
                current = nums[mid];
            } else if (target < nums[0]) {
                current = -INF;
            } else {
                current = INF;
            }
            
            if (current == target) {
                return mid;
            } else if (current < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return -1;
    }
};
