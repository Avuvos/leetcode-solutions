class Solution {
    public boolean checkAlmostEquivalent(String word1, String word2) {
        int[] counter1 = new int[26];
        int[] counter2 = new int[26];
        for (int i = 0; i < word1.length(); i++) {
            counter1[word1.charAt(i) - 'a']++;
            counter2[word2.charAt(i) - 'a']++;
        }

        for (int i = 0; i < 26; i++) {
            if (Math.abs(counter1[i] - counter2[i]) > 3) {
                return false;
            }
        }
        return true;
    }
}
