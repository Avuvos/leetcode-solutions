class Solution {
public:
    int similarPairs(vector<string>& words) {
        int res = 0;
        vector<unordered_set<char>> uniqs;
        for (int i = 0; i < words.size(); i++) {
            unordered_set<char> letters;
            for (auto c: words[i]) letters.insert(c);
            uniqs.push_back(letters);
        }
        
        for (int i = 0; i < words.size(); i++) {
            for (int j = i + 1; j < words.size(); j++) {
                bool ok = true;
                for (auto c: uniqs[i]) {
                    if (uniqs[j].find(c) == uniqs[j].end()) ok = false;
                }
                for (auto c: uniqs[j]) {
                    if (uniqs[i].find(c) == uniqs[i].end()) ok = false;
                }
                res += ok;
            }
        }
        
        
        return res;
    } 
};
