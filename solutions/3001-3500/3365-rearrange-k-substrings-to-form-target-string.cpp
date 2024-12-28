class Solution {
public:
    bool isPossibleToRearrange(string s, string t, int k) {
        int n = s.size();
        int len = n / k;
        multiset<string> need;
        for (int i = 0; i < n; i += len) {
            string cur = t.substr(i, len);
            need.insert(cur);
        }
        for (int i = 0; i < n; i += len) {
            string cur = s.substr(i, len);
            if (need.contains(cur)) {
                need.erase(need.find(cur));
            } else {
                return false;
            }
        }
        return need.empty();
    }
};
