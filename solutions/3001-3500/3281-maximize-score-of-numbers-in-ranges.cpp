class Solution {
public:
    int maxPossibleScore(vector<int>& start, int d) {
        sort(start.begin(), start.end());
        int n = start.size();
        
        auto possible = [&](int x) -> bool {
            int previous = start[0];
            for (int i = 1; i < n; i++) {
                if (start[i] + d - previous < x) {
                    return false;
                }
                previous = max(previous + x, start[i]);
            }
            return true;
        };
        
        
        int left = 0, right = 2e9, ans = 0;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (possible(mid)) {
                ans = mid;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return ans;
    }
};
