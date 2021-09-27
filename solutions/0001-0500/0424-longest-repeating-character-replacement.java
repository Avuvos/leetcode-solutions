class Solution {
    public int characterReplacement(String s, int k) {
        int res = 1, left = 0, mostFreqCharCount = 0;
        int[] count = new int [26];
        for (int right = 0; right < s.length(); right++) {
            count[s.charAt(right) - 'A']++;
            
            //most frequent character in the CURRENT WINDOW
            mostFreqCharCount = Math.max(mostFreqCharCount, count[s.charAt(right) - 'A']);

            //we need to change the size of the window minus the most frequent character 
            //of the current window, if its greater than k, then we need to shift the window
            int charsToChange = right - left + 1 - mostFreqCharCount;
            if (charsToChange > k) { //we try to replace more than k chars
                count[s.charAt(left) - 'A']--;
                left++; //shrink the window
            }
            res = Math.max(res, right - left + 1); //update result
        }
        return res;
    }
}
