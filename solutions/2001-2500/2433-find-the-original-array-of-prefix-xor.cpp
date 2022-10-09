class Solution {
public:
    vector<int> findArray(vector<int>& pref) {
        int n = pref.size();
        vector<int> res(n);
        res[0] = pref[0];
        int xor_pref = res[0];
        for (int index = 1; index < n; ++index) {
            int current = xor_pref ^ pref[index];
            res[index] = current;
            xor_pref ^= res[index];
        }
        return res;
    }
};
