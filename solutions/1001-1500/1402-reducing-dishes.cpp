class Solution {
public:
    int maxSatisfaction(vector<int>& st) {
        sort(st.begin(), st.end());
        int n = (int) st.size();
        int ans = 0;
        for (int i = 0; i < n; i++) {
            int t = 1, cur = 0;
            for (int j = i; j < n; j++) {
                cur += t*st[j];
                t++;
            }
            ans = max(ans, cur);
        }
        return ans;
    }
};
