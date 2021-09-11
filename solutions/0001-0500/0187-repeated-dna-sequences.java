class Solution {
    public List<String> findRepeatedDnaSequences(String s) {
        Map<String, Boolean> map = new HashMap<String, Boolean>();
        List<String> res = new ArrayList<>();
        for (int i=0; i<s.length()-9; i++) {
            String curr = s.substring(i, i+10);
            if (map.containsKey(curr) && map.get(curr) == false) {
                map.put(curr, true);
                res.add(curr);
            }
            else{
                if (!map.containsKey(curr)) map.put(curr, false);
            }
        }
        return res;
    }
}
