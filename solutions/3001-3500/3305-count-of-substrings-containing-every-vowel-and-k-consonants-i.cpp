class Solution {
public:
    int countOfSubstrings(string word, int k) {
        set<char> vowels = {'a', 'e', 'o', 'u', 'i'};
        int n = word.size(), ans = 0;
        for (int l = 0; l < n; l++) {
            set<char> cur;
            int cnt = 0;
            for (int r = l; r < n; r++) {
                if (vowels.contains(word[r])) {
                    cur.insert(word[r]);
                } else {
                    cnt++;
                }
                if (cur.size() == vowels.size() && cnt == k) {
                    ans++;
                }
            }
        }
        return ans;
    }
};
