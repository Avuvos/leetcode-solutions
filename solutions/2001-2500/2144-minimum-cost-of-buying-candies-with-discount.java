class Solution {
    public int minimumCost(int[] cost) {
        Arrays.sort(cost);
        int res = 0, idx = cost.length - 1;
        while (idx >= 0) {
            res += cost[idx];
            idx--;
            if (idx >= 0) res += cost[idx--];
            idx--;
        }
        return res;
    }
}
