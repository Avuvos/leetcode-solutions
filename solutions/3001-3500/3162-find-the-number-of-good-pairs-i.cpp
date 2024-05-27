class Solution {
public:
    int numberOfPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        //nums1[i] = t * (k * nums2[j]) for some t in Z
        //so ofc it should be divisible by k
        //if nums1[i] is not divisible by k, continue
        //otherwise do nums1'[i] = nums1[i] / k.
        //and now check nums1'[i] = t * nums2[j]
        //so basically check how many of the divisors are in the second array?
        map<int, int> mp;
        for (int i = 0; i < nums2.size(); i++) {
            mp[nums2[i]] += 1;
        }
        int ans = 0;
        for (int i = 0; i < nums1.size(); i++) {
            if (nums1[i] % k != 0) continue;
            nums1[i] /= k;
            for (int d = 1; d * d <= nums1[i]; d++) {
                if (nums1[i] % d == 0) {
                    ans += mp[d];
                    if (nums1[i] / d != d) {
                        ans += mp[nums1[i] / d];
                    }
                }
            }
        }
        return ans;
    }
};
