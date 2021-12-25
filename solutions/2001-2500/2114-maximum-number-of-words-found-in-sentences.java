class Solution {
    public int mostWordsFound(String[] sentences) {
        int res = 0;
        for (int i = 0; i < sentences.length; i++) {
            String [] st = sentences[i].split(" ");
            res = Math.max(res, st.length);
        }
        return res;
    }
}
