class Solution {
public:
    int maxValue(int n, int index, int maxSum) {
        int left = 1, right = maxSum, ans = 1;
        
        auto ok = [&](long long x) {    
            long long leftSum = x > index ? (x + x - index) * (index + 1)/2 
                                          :  (x + 1)*(x)/2 + (index - x + 1);
            long long rightSum = x >= n - index ? (x + x - n + 1 + index)*(n - index)/2
                                                : (x + 1)*(x)/2 + n - index - x;
            
            return leftSum + rightSum - x <= maxSum;
        };
        
        while (left <= right) {
            int mid = left + (right - left)/2;
            if (ok(mid)) {
                ans = mid;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return ans;
    }
};
