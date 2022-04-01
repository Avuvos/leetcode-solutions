class Solution {
    public void reverseString(char[] s) {
        int a = 0;
        int b = s.length-1;
        while (a < b) {
            char tmp = s[a];
            s[a] = s[b];
            s[b] = tmp;
            a++;
            b--;
        }
    }
}
