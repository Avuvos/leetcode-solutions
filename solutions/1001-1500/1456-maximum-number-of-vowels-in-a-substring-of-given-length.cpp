class Solution {
public:
    int maxVowels(string s, int k) {
        auto is_vowel = [&](char c) {
            return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
        };
        
        int current = 0, ans = 0;
        for (int r = 0, l = 0; r < s.size(); r++) {
            current += is_vowel(s[r]);         
            if (r - l + 1 > k) {
                current -= is_vowel(s[l]);
                l++;
            }
            ans = max(ans, current);
        }
        return ans;
    }
};
