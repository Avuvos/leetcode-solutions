class Solution {
public:
    int numberOfSpecialChars(string word) {
        vector<int> first(26, -1);
        vector<int> last(26, -1);
        for (int i = 0; i < word.size(); i++) {
            char c = word[i];
            if (islower(c)) {
                int j = c - 'a';
                last[j] = i;
            } else {
                int j = c - 'A';
                if (first[j] == -1) first[j] = i;
            }
        }
        int ans = 0;
        for (int i = 0; i < 26; i++) {
            if (last[i] != -1 && first[i] != -1 && last[i] < first[i]) {
                ans++;
            }
        }
        return ans;
    }
};
