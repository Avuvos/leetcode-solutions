class Solution {
    public long maximumSubsequenceCount(String text, String pattern) {
        long res = 0;
        char first = pattern.charAt(0);
        char second = pattern.charAt(1);
        long countFirst = 0;
        long countSecond = 0;
        Map<Character, List<Integer>> map = new HashMap<>();
        map.put(first, new ArrayList<>());
        map.put(second, new ArrayList<>());

        for (int i = 0; i < text.length(); i++) {
            if (text.charAt(i) == first) {
                map.get(first).add(i);
                countFirst++;

            }
            if (text.charAt(i) == second) {
                map.get(second).add(i);
                countSecond++;
            }
        }
        
        if (first == second && countFirst == 0) {
            return 0;
        }
        if (first == second) {
            return (countFirst * (countFirst + 1) )/2;
        }
        int a = 0, b = 0;
        List<Integer> flst = map.get(first);
        List<Integer> slst = map.get(second);
        while (a < flst.size() && b < slst.size()) {
            if (flst.get(a) < slst.get(b)) {
                res += (slst.size() - b);
                a++;
            }
            else {
                b++;
            }
        }
        res = Math.max(res + flst.size(), res + slst.size());
        return res;
    }
}
