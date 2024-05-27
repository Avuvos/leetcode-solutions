class Solution {
public:
    string compressedString(string word) {
        string ans;
        int i = 0;
        int n = (int) word.size();
        while (i < n) {
            int len = 1;
            char current = word[i];
            while (i + 1 < n && word[i] == word[i + 1] && len < 9) {
                i++;
                len++;
            }
            ans += to_string(len);
            ans += current;
            i++;
        }
        return ans;
    }
};
