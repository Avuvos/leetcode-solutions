class Solution {
    public int minCost(int[] startPos, int[] homePos, int[] rowCosts, int[] colCosts) {
        int res = 0;
        int pos = startPos[0];
        while (pos != homePos[0]) {
            if (pos > homePos[0]) pos--;
            else pos++;
            res += rowCosts[pos];
        }
        pos = startPos[1];
        while (pos != homePos[1]) {
            if (pos > homePos[1]) pos--;
            else pos++;
            res += colCosts[pos];
        }
        return res;
    }
}
