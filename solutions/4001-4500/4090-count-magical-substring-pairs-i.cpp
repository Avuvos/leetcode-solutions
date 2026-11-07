class Solution {
public:
    int countMagicalPairs(string s) {
        int n = s.size();
        vector<vector<int>> c(n, vector<int>(27, 0));
        for (int i = 0; i < n; i++) {
            unordered_set<char> st;
            for (int j = i; j < n; j++) {
                st.insert(s[j]);
                int cnt = st.size();
                c[i][cnt]++;
            }
        }
        int ans = 0;
        for (int i = 0; i < n; i++) {
            unordered_set<char> st;
            st.insert(s[i]);
            for (int j = i + 1; j < n; j++) {
                int sz = st.size();
                ans += c[j][sz];
                st.insert(s[j]);
            }
        }
        return ans;
    }
};
