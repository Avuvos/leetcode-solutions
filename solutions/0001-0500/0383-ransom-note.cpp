class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        vector<int> counter(26);
        for (auto c: ransomNote) {
            counter[c - 'a']++;
        }
        
        for (auto c: magazine) {
            counter[c - 'a']--;
        }
        
        for (int i = 0; i < 26; i++) {
            if (counter[i] > 0) return false;
        }
        return true;
    }
};
