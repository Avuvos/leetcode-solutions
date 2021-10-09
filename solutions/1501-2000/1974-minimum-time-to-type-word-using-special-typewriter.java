class Solution {
    public int minTimeToType(String word) {
        char pointer = 'a';
        int res = 0;
        for (int i = 0; i < word.length(); i++) {
            char ch = word.charAt(i);
            int diff = Math.abs(ch - pointer);
            res += Math.min(diff, 26 - diff) + 1;  
            pointer = ch;
        }
        return res;
    }
}
