class Solution {
    public int numberOfSubstrings(String s) {
        int cnt = 0, left = 0;
        int [] abc = new int [3]; //  0 -> a   1 -> b    2 -> c

        for (int right = 0; right < s.length(); right++) {
            char ch = s.charAt(right);
            abc[ch - 'a']++;
            while (found(abc)) {
                cnt += s.length() - right;
                abc[s.charAt(left) - 'a'] --;
                left++;
            }
        }
        return cnt;
    }
    public boolean found(int [] counter) {
        boolean ok = true;
        for (int n: counter) {
            if (n == 0) {
                ok = false;
                break;
            }
        }
        return ok;
    }
}
