class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        map<string, int> mp;
        for (auto &s: arr) {
            mp[s]++;
        }
        int cnt = 0;
        for (auto &s: arr) {
            if (mp[s] > 1) continue;
            cnt++;
            if (cnt == k) {
                return s;
            }
        }
        return "";
    }
};
