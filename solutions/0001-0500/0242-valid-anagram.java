class Solution {
    public boolean isAnagram(String s, String t) {
        int [] arr1 = new int [26];
        int [] arr2 = new int [26];
        
        if (s.length() != t.length()) 
            return false;
        
        for (int i=0; i<s.length(); i++) { //their lengths must be equal
            arr1[s.charAt(i) - 'a'] += 1; 
            arr2[t.charAt(i) - 'a'] += 1;
        }
        
        for (int i=0; i<26; i++) { //check if some char doesnt match
            if (arr1[i] != arr2[i])
                return false;
        }
        return true;
    }
}
