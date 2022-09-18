class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size(), res = 0;
        int l = 0, r = n - 1;
        int lmax = height[l], rmax = height[r];
        
        while (l < r) {
            if (height[l] <= height[r]) {
                if (height[l] > lmax) {
                    lmax = height[l];
                } else {
                    res += (lmax - height[l]);
                }
                l++;
            }
            else {
                if (height[r] > rmax) {
                    rmax = height[r];
                } else {
                    res += (rmax - height[r]);
                }
                r--;
            }
        }
        
        return res;
        
    }
};
