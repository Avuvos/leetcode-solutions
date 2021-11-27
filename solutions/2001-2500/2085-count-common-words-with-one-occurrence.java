class Solution {
    public int countWords(String[] words1, String[] words2) {
        Map<String, Integer> map1 = new HashMap<>();
        Map<String, Integer> map2 = new HashMap<>();
        for (String st1: words1) {
            map1.put(st1, map1.getOrDefault(st1, 0) + 1);
        }
        for (String st2: words2) {
            map2.put(st2, map2.getOrDefault(st2, 0) + 1);
        }
        int res = 0;
        for (Map.Entry<String, Integer> entry: map1.entrySet()) {
            String key = entry.getKey();
            int val = entry.getValue();
            if (val == 1 && map2.containsKey(key) && map2.get(key) == 1) {
                res++;
            }
        }
        return res;
    }
}
