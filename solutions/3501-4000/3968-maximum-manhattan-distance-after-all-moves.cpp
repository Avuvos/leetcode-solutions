class Solution {
public:
    int maxDistance(string moves) {
        unordered_map<char, int> mp;
        for (auto &c: moves) {
            mp[c]++;
        }
        return abs(mp['R'] - mp['L']) + abs(mp['D'] - mp['U']) + mp['_'];
    }
};
