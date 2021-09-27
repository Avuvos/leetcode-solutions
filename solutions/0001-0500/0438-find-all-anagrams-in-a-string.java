class Solution {
    public List<Integer> findAnagrams(String s, String p) {
        List<Integer> res = new ArrayList<>();
        int [] counter = new int[26];
        for (char ch: p.toCharArray()) {
            counter[ch - 'a']++;
        }
        int need = p.length();
        int left = 0;
        for (int right = 0; right < s.length(); right++) {
            char ch = s.charAt(right);
            counter[ch - 'a']--;
            need--;
            while (counter[ch - 'a'] < 0) {
                counter[s.charAt(left) - 'a']++;
                need++;
                left++;
            }
            if (need == 0) {
                res.add(left); //add the result
                need = 1; //we need 1 char since we get rid of one
                counter[s.charAt(left) - 'a']++;
                left++; //update the window
            }
        }
        return res;
    }
}
