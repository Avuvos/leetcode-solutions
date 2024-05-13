class Solution {
public:
    int maximumEnergy(vector<int>& energy, int k) {
        int n = (int) energy.size();
        vector<int> gain(n, 0);
        for (int i = n - 1; i >= 0; i--) {
            gain[i] = energy[i];
            if (i + k < n) {
                gain[i] += gain[i + k];
            }
        }
        return *max_element(gain.begin(), gain.end());
    }
};
