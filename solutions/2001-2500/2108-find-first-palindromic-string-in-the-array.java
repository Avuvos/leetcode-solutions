class Solution {
    public String firstPalindrome(String[] words) {
        for (String word: words) {
            int left = 0, right = word.length() - 1;
            boolean pal = true;
            while (left <= right) {
                if (word.charAt(left) != word.charAt(right)) {
                    pal = false;
                    break;
                }
                left++;
                right--;
            }
            if (pal) return word;
        }
        return "";
    }
}
