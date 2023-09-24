class Solution {
public:
    long long maximumSumOfHeights(vector<int>& maxHeights) {
        //assume we check if index i can be a peak, what sum will we get
        //first notice that its always possible since we have weak inequalities.
        //now for k > i, we need h[k] >= h[k + 1] >= h[k + 2] >= ... h[n].
        
        //the peak can be as high as we want, since the ones who come before and after it must be less than it.
        //so now it make sense for h[i + 1] = min(maxHeights[i + 1], h[i]).
        //                         h[i + 2] = min(maxHeights[i + 2], h[i + 1]).
        //                         h[i + 3] = min(maxHeights[h + 3], h[i +2]).
        
        //in the same way,         h[i - 1] = min(maxHeights[i - 1], h[i])
        //                         h[i - 2] = min(maxHeights[i - 2], h[i - 1])
        int n = (int) maxHeights.size();
        long long ans = 0;
        for (int i = 0; i < n; i++) {
            int prev = maxHeights[i];
            long long s = prev;
            for (int j = i - 1; j >= 0; j--) {
                long long cur = min(prev, maxHeights[j]);
                s += cur;
                prev = cur;
            }
            prev = maxHeights[i];
            for (int j = i + 1; j < n; j++) {
                long long cur = min(prev, maxHeights[j]);
                s += cur;
                prev = cur;
            }
            ans = max(ans, s);
        }
        return ans;
    }
};
