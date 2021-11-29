class Solution {
   public class Class implements Comparable<Class> {
        double pass;
        double total;
        double ratio;
        public Class(double pass, double total) {
            this.pass = pass;
            this.total = total;
            this.ratio = ((pass + 1) / (total + 1)) - (pass / total);
        }
        @Override
        public int compareTo(Class o) {
            return this.ratio > o.ratio ? 1: -1;
        }
    }

    public double maxAverageRatio(int[][] classes, int extraStudents) {
        int N = classes.length;
        PriorityQueue<Class> pq = new PriorityQueue<>(Collections.reverseOrder());
        for (int i = 0; i < N; i++) {
            pq.offer(new Class(classes[i][0], classes[i][1]));
        }
        for (int i = 0; i < extraStudents; i++) {
            if (!pq.isEmpty()) {
                Class c = pq.poll();
                pq.offer(new Class(c.pass + 1, c.total + 1));
            }
        }
        double sum = 0;
        while (!pq.isEmpty()) {
            Class c = pq.poll();
            sum += c.total != 0 ?  (c.pass / c.total): 0;
        }
        return sum / N;
    }
}
