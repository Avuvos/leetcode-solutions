class Solution {
public:
    int countMatchingSubarrays(vector<int>& a, vector<int>& pattern) {
        int n = a.size(), m = pattern.size();
        int ans = 0;
        for (int l = 0; l < n; l++) {
            if (l + m + 1 > n) break;
            bool ok = true;
            for (int i = l, idx = 0; i < l + m; i++, idx++) {
                if (a[i + 1] > a[i] && pattern[idx] != 1) ok = false;
                if (a[i + 1] == a[i] && pattern[idx] != 0) ok = false;
                if (a[i + 1] < a[i] && pattern[idx] != -1) ok = false;
            }
            ans += ok;
        }
        return ans;
        
    }
};
