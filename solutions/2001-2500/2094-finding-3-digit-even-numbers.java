class Solution {
    public Map<Integer, Integer> getDigitMap(int n) {
        Map<Integer, Integer> digMap = new HashMap<>();
        while (n > 0) {
            digMap.put(n % 10, digMap.getOrDefault(n % 10, 0) + 1);
            n = n / 10;
        }
        return digMap;
    }

    public boolean matches(Map<Integer, Integer> digMap) {
        for (Map.Entry<Integer, Integer> entry: digMap.entrySet()) {
            if (entry.getValue() != 0) {
                return false;
            }
        }
        return true;
    }
    
    public int[] findEvenNumbers(int[] digits) {
        List<Integer> res = new ArrayList<>();
        for (int i = 100; i < 1000; i += 2) {
            Map<Integer, Integer> digMap = getDigitMap(i);
            for (int dig: digits) {
                if (digMap.containsKey(dig) && digMap.get(dig) > 0) {
                    digMap.put(dig, digMap.get(dig) - 1);
                }
            }
            if (matches(digMap)) {
                res.add(i);
            }
        }
        int[] ans = new int[res.size()];
        for (int i = 0; i < res.size(); i++) {
            ans[i] = res.get(i);
        }
        return ans;
    }
}
