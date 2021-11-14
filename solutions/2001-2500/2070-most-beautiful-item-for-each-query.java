class Solution {
    public static int[] maximumBeauty(int[][] items, int[] queries) {
        int[] res = new int[queries.length];
        Arrays.sort(items, Comparator.comparingInt(a -> a[0]));
        for (int i = 1; i < items.length; i++) {
            items[i][1] = Math.max(items[i][1], items[i - 1][1]);
        }
        for (int i = 0; i < queries.length; i++) {
            int idx = binarySearch(items, 0, items.length - 1, queries[i]);
            res[i] = idx > 0 ? items[idx - 1][1] : 0;
        }
        return res;
    }
    public static int binarySearch(int[][] items, int left, int right, int price) {
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (items[mid][0] <= price) {
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }
        return left;
    }
}
