class Solution {
    public int minimumMoves(String s) {
        int i = 0, cnt = 0;
        while (i < s.length()) {
            if (s.charAt(i) == 'X') {
                cnt++;
                i += 2;
            }
            i++;
        }
        return cnt;
    }
}
