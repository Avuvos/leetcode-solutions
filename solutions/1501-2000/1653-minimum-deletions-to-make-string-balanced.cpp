class Solution {
public:
    int minimumDeletions(string s) {
        int n = (int) s.size();
        vector<int> suffix_a(n + 1, 0), suffix_b(n + 1, 0);
        for (int i = n - 1; i >=0; i--) {
            suffix_a[i] = suffix_a[i + 1] + (s[i] == 'a');
            suffix_b[i] = suffix_b[i + 1] + (s[i] == 'b');
        }
        if (suffix_b[0] == 0 || suffix_a[0] == 0) {
            return 0;
        }
        int best = n, sum = 0, must = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == 'b') {
                best = min(best, sum + suffix_a[i + 1]);
                sum++;
                if (suffix_a[i + 1] > 0) {
                    must++;
                }
            }
        }
        best = min(best, must);
        return best;
    }
};
