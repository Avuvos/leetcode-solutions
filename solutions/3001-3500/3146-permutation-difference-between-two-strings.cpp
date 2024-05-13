class Solution {
public:
    int findPermutationDifference(string s, string t) {
        vector<int> ind(26, 0);
        for (int i = 0; i < s.size(); i++) {
            ind[s[i] - 'a'] = i;
        }
        int ans = 0;
        for (int i = 0; i < t.size(); i++) {
            ans += abs(i - ind[t[i] - 'a']);
        }
        return ans;
    }
};
