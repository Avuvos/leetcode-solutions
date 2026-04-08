class Solution {
public:
    int minOperations(string s) {
        if (is_sorted(s.begin(), s.end())) {
            return 0;
        }
        int n = s.size();
        if (n == 2) {
            return -1;
        }
        int ans = 3;
        string t = s;
        sort(t.begin(), t.end() - 1);
        if (is_sorted(t.begin(), t.end())) {
            ans = min(ans, 1);
        }
        sort(t.begin() + 1, t.end());
        if (is_sorted(t.begin(), t.end())) {
            ans = min(ans, 2);
        }
        t = s;
        sort(t.begin() + 1, t.end());
        if (is_sorted(t.begin(), t.end())) {
            ans = min(ans, 1);
        }
        sort(t.begin(), t.end() - 1);
        if (is_sorted(t.begin(), t.end())) {
            ans = min(ans, 2);
        }
        return ans;
    }
};
