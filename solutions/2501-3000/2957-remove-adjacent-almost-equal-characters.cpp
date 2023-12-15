class Solution {
public:
    int removeAlmostEqualCharacters(string word) {
        int ans = 0;
        for (int i = 0; i + 1 < word.size(); i++) {
            int c1 = word[i + 1] - 'a';
            int c2 = word[i] - 'a';
            if (abs(c1 - c2) <= 1) {
                ans++;
                i++;
            }
        }
        return ans;
    }
};
