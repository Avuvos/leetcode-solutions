class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> cnt;
        for (auto &a: arr) cnt[a]++;
        unordered_set<int> s;
        for (auto [key, val]: cnt) {
            if (s.find(val) != s.end()) return false;
            s.insert(val);
        }
        return true;
    }
};
