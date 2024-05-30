class Solution {
public:
    int countTriplets(vector<int>& arr) {
        int n = (int) arr.size();
        int ans = 0;
        for (int i = 0; i < n; i++) {
            int x = 0;
            for (int j = i; j < n; j++) {
                x ^= arr[j];
                if (x == 0) {
                    ans += (j - i);
                }
            }
        }
        return ans;
    }
};
