class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end());
        int ans = 0, r = 0;
        for (auto &m: meetings) {
            ans += max(0, m[0] - r - 1);
            r = max(r, m[1]);
        }
        ans += days - r;
        return ans;
    }
};
