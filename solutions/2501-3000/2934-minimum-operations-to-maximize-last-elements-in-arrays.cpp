class Solution {
public:
    int minOperations(vector<int>& nums1, vector<int>& nums2) {
        int n = (int) nums1.size();
        
        auto check = [&](vector<int> a, vector<int> b) {
            int res = 0;
            for (int i = 0; i < n - 1; i++) {
                if (a[i] > a[n - 1]) {
                    swap(a[i], b[i]);
                    res++;
                }
                if (b[i] > b[n - 1]) {
                    swap(a[i], b[i]);
                    res++;
                }
            }

            if (*max_element(a.begin(), a.end()) == a[n - 1] &&
                   *max_element(b.begin(), b.end()) == b[n - 1])
                return res;
            return -1;
        };
        int ans = n + 1;
        int res = check(nums1, nums2);
        if (res != -1) {
            ans = min(ans, res);
        }
        swap(nums1[n - 1], nums2[n - 1]);
        res = check(nums1, nums2);
        if (res != -1) {
            ans = min(ans, 1 + res);
        }
        return ans <= n ? ans : -1;
    }
};
