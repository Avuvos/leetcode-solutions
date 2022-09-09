class Solution {
public:

    static bool sort_players(const vector<int> &a, const vector<int> &b) {
        return (a[0] == b[0] ? a[1] > b[1] : a[0] < b[0]);
    }

    int numberOfWeakCharacters(vector<vector<int>>& properties) {
        int res = 0;
        int n = properties.size();
        sort(properties.begin(), properties.end(), sort_players);
        int best_attack = properties[n - 1][0];
        int best_defense = properties[n - 1][1];
        for (int index = n - 2; index >= 0; index--) {
            if (properties[index][1] < best_defense && properties[index][0] < best_attack)
                res++;
            best_defense = max(best_defense, properties[index][1]);
        }
        return res;
    }
};
