class Solution {
public:
    vector<int> countWordOccurrences(vector<string>& chunks, vector<string>& queries) {
        unordered_map<string, int> mp;
        string s;
        for (auto &c: chunks) {
            s += c;
        }
        int n = s.size();
        int i = 0;
        string cur;
        while (i < n) {
            if (s[i] == ' ') {
                mp[cur]++;
                cur = "";
                i++;
                continue;
            }
            if (s[i] == '-') {
               if (i + 1 < n && (s[i + 1] == '-' || s[i + 1] == ' ')) {
                mp[cur]++;
                cur = "";
                while (i < n && (s[i] == '-' || s[i] == ' ')) {
                    i++;
                }
                continue;
               } else {
                if (!cur.empty() && i + 1 < n) cur += s[i];
                i++;
                continue;
               }
            }
            cur += s[i];
            i++;
        }
        mp[cur]++;

        vector<int> ans;
        for (auto &q: queries) {
            ans.push_back(mp[q]);
        }
        return ans;
    }
};
