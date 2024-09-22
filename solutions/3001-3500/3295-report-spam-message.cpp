class Solution {
public:
    bool reportSpam(vector<string>& message, vector<string>& bannedWords) {
        set<string> banned(bannedWords.begin(), bannedWords.end());
        int count = 0;
        for (auto &word: message) {
            if (banned.contains(word)) {
                count++;
            }
        }
        return count >= 2;
    }
};
