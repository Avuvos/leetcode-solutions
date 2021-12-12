class Solution {
    public int countPoints(String rings) {
        Map<Integer, String> map = new HashMap<>();
        for (int i = 0; i < rings.length() - 1; i += 2) {
            String color = String.valueOf(rings.charAt(i));
            int rod = rings.charAt(i + 1);
            map.put(rod, map.getOrDefault(rod, "") + color);
        }
        int res = 0;
        for (Map.Entry<Integer, String> entry: map.entrySet()) {
            String st = entry.getValue();
            if (st.contains("R") && st.contains("G") && st.contains("B")) {
                res++;
            }
        }
        return res;   
    }
}
