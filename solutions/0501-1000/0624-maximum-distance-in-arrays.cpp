class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int mx = -10001, mn = 10001, ans = 0;
        for (int i = 0; i < arrays.size(); i++) {
            ans = max({ans, mx - arrays[i].front(), arrays[i].back() - mn});
            mx = max(mx, arrays[i].back());
            mn = min(mn, arrays[i].front());
        }
        return ans;
    }
};
