class Solution {
public:
    vector<string> shortestSubstrings(vector<string>& arr) {
        int n = (int) arr.size();
        map<string, int> mp;
        
        auto update = [&](string &s, int delta) -> string {
            string best = string(30, 'z');
            for (int i = 0; i < s.size(); i++) {
                string cur;
                for (int j = i; j < s.size(); j++) {
                    cur.push_back(s[j]);
                    mp[cur] += delta;
                    if (delta == 1 && mp[cur] == 1) {
                        if (cur.size() < best.size() || (cur.size() == best.size() && cur < best)) {
                            best = cur;
                        }
                    }
                }
            }
            return best.size() < 30 ? best : "";
        };
        
        for (auto &s: arr) {
            update(s, 1);
        }
        
        vector<string> ans(n);
        for (int i = 0; i < n; i++) {
            update(arr[i], -1);
            ans[i] = update(arr[i], 1);
        }
        return ans;
    }
};
