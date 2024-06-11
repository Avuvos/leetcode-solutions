class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        int n = (int) arr1.size(), m = (int) arr2.size();
        vector<int> ans(n);
        map<int, int> count;
        for (auto& x: arr1) {
            count[x]++;
        }
        int i = 0, j = 0;
        while (i < n && j < m) {
            while (count[arr2[j]] > 0) {
                count[arr2[j]]--;
                ans[i++] = arr2[j];
            }
            count.erase(arr2[j]);
            j++;
        }
        for (auto [key, val]: count) {
            while (val > 0) {
                ans[i++] = key;
                val--;
            }
        }
        return ans;
    }
};
