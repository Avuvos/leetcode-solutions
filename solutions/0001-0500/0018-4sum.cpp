class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& A, int target) {
        int n = (int) A.size();
        sort(A.begin(), A.end());
        vector<vector<int>> ans;
        vector<vector<int>> dups;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                long long t = (long long) target - A[i] - A[j];
                int l = j + 1, r = n - 1;
                while (l < r) {
                    if (A[l] + A[r] == t) {
                        vector<int> current = {A[l], A[r], A[i], A[j]};
                        sort(current.begin(), current.end());
                        dups.push_back(current);
                        l++;
                        r--;
                    } else if (A[l] + A[r] > t) {
                        r--;
                    } else {
                        l++;
                    }
                }
            }
        }
        sort(dups.begin(), dups.end());
        for (auto &v: dups) {
            if (ans.empty() || v != ans.back()) {
                ans.push_back(v);
            }
        }
        return ans;
    }
};
