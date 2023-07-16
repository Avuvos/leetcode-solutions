class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        int n = (int) nums.size();
        vector<int> valPrefix(n, -1);
        map<int, int> cntPrefix;
        
        int c = 0, mx = 0, mxVal = 0;
        for (int i = 0; i < n; i++) {
            cntPrefix[nums[i]]++;
            if (cntPrefix[nums[i]] > mx) {
                mx = cntPrefix[nums[i]];
                mxVal = nums[i];
            }
            c++;
            if (2 * mx > c) {
                valPrefix[i] = mxVal;
            }
        }
        
        vector<int> valSuffix(n + 1, -1);
        map<int, int> cntSuffix;
        c = 0;
        mx = 0;
        mxVal = 0;
        for (int i = n - 1; i >= 0; i--) {
            cntSuffix[nums[i]]++;
            if (cntSuffix[nums[i]] > mx) {
                mx = cntSuffix[nums[i]];
                mxVal = nums[i];
            }
            c++;
            if (2 * mx > c) {
                valSuffix[i] = mxVal;
            }
        }
        
        for (int i = 0; i < n; i++) {
            if (valPrefix[i] == valSuffix[i + 1] && valPrefix[i] != -1 && valSuffix[i + 1] != -1) {
                return i;
            }
        }
        
        return -1;
        
    }
};
