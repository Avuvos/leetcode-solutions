typedef long long ll;
class Solution {
public:
    long long countQuadruplets(vector<int>& nums) {
        int n = (int)nums.size();
        vector<vector<ll>> lt(n, vector<ll>(n, 0)); //lt[i][j] how many numbers are less than nums[i] with smaller index than j
        vector<vector<ll>> gt(n, vector<ll>(n, 0)); //gt[i][j]how many numbers are greater than nums[i] with greater index than j
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (j > 0)
                    lt[i][j] = lt[i][j - 1];
                if (nums[j] < nums[i]) {
                    lt[i][j]++;
                }
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = n - 1; j > i; j--) {
                if (j + 1 < n)
                    gt[i][j] = gt[i][j + 1];
                if (nums[j] > nums[i]) {
                    gt[i][j]++;
                }
            }
        }
        
        ll res = 0;
        for (int j = 0; j < n; j++) {
            for (int k = j + 1; k < n; k++) {
                if (nums[j] > nums[k]) {
                    res += gt[j][k]*lt[k][j];
                }
            }
        }
        
        return res;
    }
};
