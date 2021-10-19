class Solution {
    public int waysToMakeFair(int[] nums) {
        int res = 0, n = nums.length;
        if (n == 1) return 1;
        int[] oddPrefixSum = new int[n];
        int[] evenPrefixSum = new int[n];
        evenPrefixSum[0] = nums[0];
        oddPrefixSum[1] = nums[1];
        for (int i = 2; i < n; i++) {
            if (i % 2 == 0) evenPrefixSum[i] += evenPrefixSum[i - 2] + nums[i];
            else oddPrefixSum[i] += oddPrefixSum[i - 2] + nums[i];
        }
        int oddTotalSum = oddPrefixSum[n - 1] + oddPrefixSum[n - 2];
        int evenTotalSum = evenPrefixSum[n - 1] + evenPrefixSum[n - 2];
        for (int i = 0; i < n; i++) {
            if (i == 0) {
                if (evenTotalSum - nums[i] == oddTotalSum) {
                    res++;
                }
                continue;
            }
            int evenSum = -1, oddSum = -1;
            if (i % 2 == 0) {
                evenSum = evenPrefixSum[i] - nums[i] + (oddTotalSum - oddPrefixSum[i - 1]);
                oddSum = oddPrefixSum[i - 1] + (evenTotalSum - evenPrefixSum[i]);
            }
            else {
                evenSum = evenPrefixSum[i - 1] + (oddTotalSum - oddPrefixSum[i]);
                oddSum = oddPrefixSum[i] - nums[i] + (evenTotalSum - evenPrefixSum[i - 1]);
            }
            if (evenSum == oddSum) res++;
        }
        return res;
    }
}
