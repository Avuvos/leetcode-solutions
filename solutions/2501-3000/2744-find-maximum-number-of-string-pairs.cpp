class Solution {
public:
    int maximumNumberOfStringPairs(vector<string>& words) {
        set<string> s;
        int ans = 0;
        for (auto &w: words) {
            string tmp = w;
            reverse(w.begin(), w.end());
            if (s.find(w) != s.end()) {
                ans++;
                s.erase(w);
            }
            s.insert(tmp);
        }
        return ans;
    }
};
