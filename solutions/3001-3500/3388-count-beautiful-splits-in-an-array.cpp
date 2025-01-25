class Solution {
public:
    
    vector<int> z_function(vector<int> &a) {
        int n = a.size();
        vector<int> z(n);
        int l = 0, r = 0;
        for (int i = 1; i < n; i++) {
            if (i < r) {
                z[i] = min(r - i, z[i - l]);
            }
            while (i + z[i] < n && a[z[i]] == a[i + z[i]]) {
                z[i]++;
            }
            if (i + z[i] > r) {
                l = i;
                r = i + z[i];
            }
        }
        return z;
    }
    
    int beautifulSplits(vector<int>& nums) {
        //basically for each pair i,j.
        //we need to determine if the subarray nums[i..j] is also the same as nums[j...j + (j - i)]
        int n = nums.size();
        if (n <= 2) return 0;
        vector<vector<int>> zs;
        vector<int> suffix;
        for (int i = n - 1; i >= 0; i--) {
            suffix.push_back(nums[i]);
            reverse(suffix.begin(), suffix.end());
            auto zd = z_function(suffix);
            zs.push_back(zd);
            reverse(suffix.begin(), suffix.end());
        }
        reverse(zs.begin(), zs.end());
        auto z = zs[0];
        int ans = 0;
        for (int i = 0; i < n - 2; i++) {
            // basically ask how many arrays there are if nums1 is nums[0...i].
            int len1 = i + 1;
            for (int j = i + 1; j < n - 1; j++) {
                //and nums2 = nums[i + 1 ... j], meaning nums3 = nums[j + 1...n - 1]
                int len2 = j - i;
                if (len2 >= len1 && z[i + 1] >= len1) {
                    ans++;
                    continue;
                }
                int len3 = n - 1 - j;
                int sz = zs[i + 1].size();
                if (len3 >= len2 && zs[i + 1][sz - len3] >= len2) {
                    ans++;
                    continue;
                }
            }
        }
        return ans;
    }
};
