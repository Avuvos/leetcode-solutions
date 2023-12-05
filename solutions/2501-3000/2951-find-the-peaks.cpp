class Solution {
public:
    vector<int> findPeaks(vector<int>& a) {
        vector<int> ans;
        for (int i = 1; i < a.size() - 1; i++) {
            if (a[i] > a[i - 1] && a[i] > a[i + 1]) {
                ans.push_back(i);
            }
        }
        return ans;
    }
};
