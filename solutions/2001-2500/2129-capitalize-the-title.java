class Solution {
    public String capitalizeTitle(String title) {
      StringBuilder result = new StringBuilder();
        for (String word: title.split(" ")) {
            if (word.length() == 1 || word.length() == 2) {
                result.append(word.toLowerCase());
            }
            else {
                char [] w = word.toCharArray();
                for (int i = 0; i < w.length; i++) {
                    if (i == 0) result.append(Character.toUpperCase(w[i]));
                    else result.append(Character.toLowerCase(w[i]));
                }
            }
            result.append(" ");
        }
        result.deleteCharAt(result.length() - 1);
        return result.toString(); 
    }
}
