class Solution {
public:
    long long minCost(vector<int>& arr1, vector<int>& arr2, long long k) {
        long long s1 = 0, s2 = k;
        int n = arr1.size();
        for (int i = 0; i < n; i++) {
            s1 += abs(arr1[i] - arr2[i]);
        }
        sort(arr1.begin(), arr1.end());
        sort(arr2.begin(), arr2.end());
        for (int i = 0; i < n; i++) {
            s2 += abs(arr1[i] - arr2[i]);
        }
        return min(s1, s2);
    }
};
