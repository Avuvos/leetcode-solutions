class Solution {
    public int numberOfBeams(String[] bank) {
        int prevWaiting = 0;
        int res = 0;
        for (int i = 0; i < bank.length; i++) {
            String s = bank[i];
            int waiting = 0;
            for (int j = 0; j < s.length(); j++) {
                if (s.charAt(j) == '1') {
                    waiting++;
                }
            }
            if (waiting > 0) {
                res += prevWaiting*waiting;
                prevWaiting = waiting;
            }
        }
        return res;
    }
}
