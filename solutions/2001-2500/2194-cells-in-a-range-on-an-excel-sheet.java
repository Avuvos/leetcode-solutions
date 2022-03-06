class Solution {
    public List<String> cellsInRange(String s) {
        List<String> res = new ArrayList<>();
        for (char r = s.charAt(0); r <= s.charAt(3); r++) {
            for (char c = s.charAt(1); c <= s.charAt(4); c++) {
                String str = String.valueOf(r) + c;
                res.add(str);
            }
        }
        return res;
    }
}
