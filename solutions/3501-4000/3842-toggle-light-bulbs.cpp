class Solution {
public:
    vector<int> toggleLightBulbs(vector<int>& bulbs) {
        vector<int> state(100);
        for (auto &b: bulbs) {
            state[b - 1] ^= 1;
        }
        vector<int> ans;
        for (int i = 0; i < 100; i++) {
            if (state[i]) {
                ans.push_back(i + 1);
            }
        }
        return ans;
    }
};
