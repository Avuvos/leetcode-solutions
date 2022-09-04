class Solution {
public:
    bool checkDistances(string s, vector<int>& distance) {
        unordered_map<char, vector<int>> mp;
        for (int index = 0; index < s.size(); ++index) {
            mp[s[index]].push_back(index);
        }

        for (auto a: s) {
            if (distance[a - 'a'] != mp[a][1] - mp[a][0] - 1)
                return false;
        }
        return true;

    }
};
