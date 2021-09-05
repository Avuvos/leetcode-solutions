class Solution {
    public int countQuadruplets(int[] nums) {
        int cnt = 0;
        int n = nums.length;
        for (int i=0; i<n; i++) {
            for (int j=i+1; j<n; j++) {
                for (int k=j+1; k<n; k++) {
                    for (int p=k+1; p<n; p++) {
                        if (nums[i]+nums[j]+nums[k]==nums[p]) {
                            cnt++;
                        }
                    }
                
                }
            }
        }
        return cnt;
    }
}
