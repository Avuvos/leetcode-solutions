class Solution {
public:
    int maximumLength(string s) {
        int n = (int) s.size();
        int ans = -1;
        for (char c = 'a'; c <= 'z'; c++) {
            int left = 1, right = n + 1;
            while (left <= right) {
                int mid = left + (right - left)/2;
                int streak = 0, cnt = 0;
                for (int i = 0; i < n; i++) {
                    if (s[i] == c) {
                        streak++;
                    } else {
                        streak = 0;
                    }
                    if (streak >= mid) {
                        cnt++;
                    }
                }
                if (cnt >= 3) {
                    left = mid + 1;
                    ans = max(ans, mid);
                } else {
                    right = mid - 1;
                }
            }
        }
        return ans;
    }
};
