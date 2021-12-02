class Solution {
    public boolean carPooling(int[][] trips, int capacity) {
        Arrays.sort(trips, Comparator.comparingInt(a -> a[1]));
        PriorityQueue<int[]> q = new PriorityQueue<>(Comparator.comparingInt(a->a[0]));
        for (int[] t: trips) {
            if (capacity < 0) return false;
            int ppl = t[0], start = t[1], end = t[2];
            while (!q.isEmpty() && q.peek()[0] <= start) {
                int[] cur = q.poll();
                capacity += cur[1];
            }
            capacity -= ppl;
            q.offer(new int[]{end, ppl});
        }
        return capacity >= 0;
    }
}
