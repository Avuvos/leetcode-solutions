class Solution {
    public int minSteps(String s, String t) {
        int [] sCnt = new int[26];
        int [] tCnt = new int[26];
        for (int i = 0; i < s.length(); i++) {
            sCnt[s.charAt(i) - 'a']++;
        }
        
        for (int i = 0; i < t.length(); i++) {
            tCnt[t.charAt(i) - 'a']++;
        }
        int res = 0;
        for (int i = 0; i < 26; i++) {
            res += Math.abs(sCnt[i] - tCnt[i]);
        }
        
        return res;
        
    }
}
