class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> words(wordDict.begin(), wordDict.end());
        map<pair<int, string>, bool> mp;
        
        function<bool(int, string&)> dfs = [&](int index, string& current) {
            if (index >= s.size()) {
                return current.size() == 0 || words.find(current) != words.end();
            }
            if (mp.find(make_pair(index, current)) != mp.end()) {
                return mp[make_pair(index, current)];
            }
            bool ok = false;
            current.push_back(s[index]);
            ok |= dfs(index + 1, current);
            current.pop_back();
            if (words.find(current) != words.end()) {
                string nxt;
                ok |= dfs(index, nxt);
            }
            return mp[make_pair(index, current)] = ok;
        };
        string current;
        return dfs(0, current);
    }
};
