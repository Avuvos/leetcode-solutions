class Solution {
public:
    string findLongestWord(string s, vector<string>& dictionary) {
        auto is_sub = [&](string x) {
            int j = 0;
            for (int i = 0; i < s.size() && j < x.size(); i++) {
                if (s[i] == x[j]) j++;
            }
            return j == x.size();
        };
        string ans;
        sort(dictionary.begin(), dictionary.end());
        for (auto &word: dictionary) {
            if (word.size() > ans.size() && is_sub(word)) {
                ans = word;
            }
        }
        return ans;
    }
};
