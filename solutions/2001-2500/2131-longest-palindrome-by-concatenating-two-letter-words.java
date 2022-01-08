class Solution {
    public int longestPalindrome(String[] words) {
         int res = 0;
         Map<String, Integer> map = new HashMap<>();
         
         for (String word: words) {
             String rev = String.valueOf(word.charAt(1)) + word.charAt(0);
             if (map.containsKey(rev) && map.get(rev) > 0) {
                 map.put(rev, map.get(rev) - 1);
                 res += 4;
             }
             else {
                 map.put(word, map.getOrDefault(word, 0) + 1);
             }
         }
         for (String word: map.keySet()) {
             if (map.get(word) > 0 && word.charAt(0) == word.charAt(1)) {
                 return res + 2;
             }
         }
         return res;
    }
}
