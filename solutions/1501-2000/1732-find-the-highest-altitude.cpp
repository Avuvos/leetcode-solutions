class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        vector<int> alt = {0};
        for (auto &x: gain) {
            alt.push_back(x + alt.back());
        }
        return *max_element(alt.begin(), alt.end());
    }
};
