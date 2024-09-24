class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        unordered_set<string> st;
        for (auto &x: arr1) {
            string s = to_string(x);
            string cur;
            for (int i = 0; i < s.size(); i++) {
                cur += s[i];
                st.insert(cur);
            }
        }
        int ans = 0;
        for (auto &x: arr2) {
            string s = to_string(x);
            string cur;
            for (int i = 0; i < s.size(); i++) {
                cur += s[i];
                if (st.contains(cur)) {
                    ans = max(ans, (int)cur.size());
                }
            }
        }
        return ans;
    }
};
