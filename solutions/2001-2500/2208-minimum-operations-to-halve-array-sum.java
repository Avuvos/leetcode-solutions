class Solution {
    public int halveArray(int[] nums) {
        double sum = 0;
        PriorityQueue<Double> pq = new PriorityQueue<>(Collections.reverseOrder());
        for (int n: nums) {
            sum += n;
            pq.offer((double) n);
        }
        double reqSum = sum / 2.0;
        int ops = 0;
        while (sum > reqSum) {
            double num = pq.poll();
            sum -= num;
            num = num / 2;
            sum += num;
            pq.offer(num);
            ops++;
        }
        return ops;
    }
}
