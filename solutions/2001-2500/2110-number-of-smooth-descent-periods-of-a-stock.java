class Solution {
    public long getDescentPeriods(int[] prices) {
        long res = 1;
        long streak = 1;
        for (int i = 0; i < prices.length - 1; i++) {
            if (prices[i] == prices[i + 1] + 1) {
                streak++;
            }
            else {
                streak = 1;
            }
            res += streak;
        }
        return res;
    }
}
