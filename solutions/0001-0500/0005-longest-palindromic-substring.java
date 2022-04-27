class Solution {
    public String longestPalindrome(String s) {
        String res = "";
        
        for (int i=0; i<s.length(); i++) { 
            String odd = extendPal(i, i, s);//check odd length palindroms
            String even = extendPal(i, i+1, s);//check even length palindroms
            
            if (odd.length() > res.length()) {
                res = odd;
            }
            if (even.length() > res.length()) {
                res = even;
            }
        }
        return res;
    }
    
    public String extendPal(int left, int right, String s) {
        String res = "";
        int max = 0;
        while (left >= 0 && right < s.length() && s.charAt(left)==s.charAt(right)) {
            String curr = s.substring(left, right + 1);
            if (curr.length() > max) {
                res = curr;
                max = curr.length();
            }
            left--;
            right++;
        }
        return res;
    }
    
}
