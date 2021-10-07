class Solution {
    public String longestCommonPrefix(String[] strs) {
        String res = "", shortestWord = strs[0];
        for (String str: strs) {
            if (str.length() < shortestWord.length()) {
                shortestWord = str;
            }
        }
        for (int i = 1; i <= shortestWord.length(); i++) {
            for (String str: strs) {
                if (!str.equals(shortestWord)) {
                    if (i >= str.length() || !str.substring(0, i).equals(shortestWord.substring(0, i))) {
                        return res;
                    }
                }
            }
            res = shortestWord.substring(0, i);
        }
        return res;
    }
}
