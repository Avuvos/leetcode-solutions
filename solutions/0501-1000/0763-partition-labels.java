class Solution {
    public List<Integer> partitionLabels(String s) {
        List<Integer> res = new ArrayList<>();
        int [] map = new int [26];
         for (int i=0; i<s.length(); i++) {
            map[s.charAt(i) - 'a'] = i;
        }
        int left = 0;
        int right = 0;
        for (int i=0; i<s.length(); i++) {
            right = Math.max(right, map[s.charAt(i) - 'a']);
            if (right == i) {
                res.add(right - left + 1);
                left = right + 1;
            }
        }
        return res;
    }
}
