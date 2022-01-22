class Solution {
    public int numberOfArrays(int[] differences, int lower, int upper) {
        int prevNum = lower;
        int nextNum = 0;
        int minVal = prevNum, maxVal = prevNum;
        for (int i = 0; i < differences.length; i++) {
            nextNum = differences[i] + prevNum;
            minVal = Math.min(minVal, nextNum);
            maxVal = Math.max(maxVal, nextNum);
            prevNum = nextNum;
        }
        int res = 0;
        for (int i = 0; i < upper - lower + 1; i++) {
            if (maxVal + i <= upper && minVal + i >= lower) {
                res++;
            }
        }
        return res;
    }
}
