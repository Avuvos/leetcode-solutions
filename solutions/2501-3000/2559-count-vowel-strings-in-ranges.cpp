class Solution {
public:
    bool isVowel(char c) {
        string vowels = "aeiou";
        for (auto ch: vowels) if (ch == c) return true;
        return false;
    }
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        int n = (int) words.size();
        vector<int> ps(n + 1, 0);
        int q = queries.size();
        vector<int> res(q);
        for (int i = 0; i < words.size(); i++) {
            char start = words[i][0];
            char end = words[i][words[i].size() - 1];
            ps[i + 1] = ps[i];
            if (isVowel(start) && isVowel(end)) {
                ps[i + 1]++;
            }
        }
        for (int i = 0; i < q; i++) {
            int l = queries[i][0], r = queries[i][1];
            res[i] = ps[r + 1] - ps[l];
        }
        return res;
    }
};
