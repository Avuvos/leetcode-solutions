class Solution {
public:
    string reorganizeString(string s) {
        vector<pair<int, int>> cnt(26);
        string ans;
        int n = (int) s.size();
        for (int i = 0; i < n; i++) {
            cnt[s[i] - 'a'].first++;
        }
        for (int i = 0; i < 26; i++) {
            cnt[i].second = i;
        }
        sort(cnt.rbegin(), cnt.rend());
        vector<char> res(n);
        int p = 0;
        for (int i = 0; i < 26; i++) {
            while (cnt[i].first > 0) {
                res[p] = char(cnt[i].second + 'a');
                p += 2;
                if (p >= n) p = 1;
                cnt[i].first--;
            }
        }
        for (int i = 0; i < n; i++) {
            ans.push_back(res[i]);
            if (i + 1 < n && res[i] == res[i + 1]) {
                return "";
            }
        }
        return ans;
    }
};
