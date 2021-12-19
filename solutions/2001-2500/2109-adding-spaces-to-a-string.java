class Solution {
    public String addSpaces(String s, int[] spaces) {
        int idx = 0;
        int currSpace = spaces[idx];
        StringBuilder res = new StringBuilder();
        for (int i = 0; i < s.length(); i++) {
            if (i == currSpace) {
                res.append(" ");
                idx++;
                if (idx < spaces.length) {
                    currSpace = spaces[idx];
                }
            }
            res.append(s.charAt(i));
        }
        return res.toString();
    }
}
