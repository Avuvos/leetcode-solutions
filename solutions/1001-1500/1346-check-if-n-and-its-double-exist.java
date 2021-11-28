class Solution {
    public boolean checkIfExist(int[] arr) {
        Set<Integer> set = new HashSet<>();
        for (int n: arr) {
            if (set.contains(n)) return true;
            if (n % 2 == 0) set.add(n / 2);
            set.add(n * 2);
        }
        return false;
    }
}
