class Solution {
public:
    int minimumLevels(vector<int>& a) {
        int suffix_sum = 0;
        int n = (int) a.size();
        for (int i = n - 1; i >= 0; i--) {
            suffix_sum += (a[i] == 1 ? 1 : -1);
        }
        int sum = 0;
        for (int i = 0; i < n - 1; i++) {
            int val = a[i] == 1 ? 1 : -1;
            suffix_sum -= val;
            sum += val;
            if (sum > suffix_sum) {
                return i + 1;
            }
        }
        return -1;
    }
};
