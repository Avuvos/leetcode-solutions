class Solution {
public:
    vector<string> split(string str, const string& delimiter) {
        vector<string> res;
        size_t pos;
        string token;
        while ((pos = str.find(delimiter)) != string::npos) {
            token = str.substr(0, pos);
            res.push_back(token);
            str.erase(0, pos + delimiter.length());
        }
        res.push_back(str);
        return res;
    }
    bool wordPattern(string pattern, string s) {
        unordered_map<char, string> mp;
        unordered_map<string, char> mp2;
        vector<string> words = split(s, " ");
        if (words.size() != pattern.size()) return false;
        for (int i = 0; i < words.size(); i++) {
            if (mp.find(pattern[i]) == mp.end()) {
                if (mp2.find(words[i]) != mp2.end() && mp2[words[i]] != pattern[i]) return false;
                mp[pattern[i]] = words[i];
                mp2[words[i]] = pattern[i];
            } else if (mp[pattern[i]] != words[i]) {
                return false;
            }
        }
        return true;
    }
};
