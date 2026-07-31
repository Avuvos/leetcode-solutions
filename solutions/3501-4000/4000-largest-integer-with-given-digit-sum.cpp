class Solution {
public:
    int largestInteger(int n, int s) {
        int ans = 0;
        for (int i = 0; i < n; i++) {
            int d = min(s, 9);
            s -= d;
            ans = ans * 10 + d;
        }
        return s > 0 ? -1 : ans;
    }
};
