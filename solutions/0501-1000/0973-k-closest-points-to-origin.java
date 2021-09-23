class Solution {
    public int[][] kClosest(int[][] points, int k) {
        PriorityQueue<Double> pq = new PriorityQueue<>();
        Map<Double, List<int[]>> pointDist = new HashMap<>();
        int [][] res = new int[k][2];

        for (int[] point: points) {
            double distFromOrigin = eucDist(point[0], point[1], 0, 0);
            if (pointDist.containsKey(distFromOrigin)) {
                List<int[]> lst = pointDist.get(distFromOrigin);
                lst.add(point);
            }
            else {
                List<int[]> lst2 = new ArrayList<>();
                lst2.add(point);
                pointDist.put(distFromOrigin, lst2);
            }
            pq.offer(distFromOrigin);
        }
        int i=0;
        while (k > 0) {
            List<int[]> pts = pointDist.get(pq.poll());
            for (int[] pt : pts) {
                res[i] = pt;
                i++;
                k--;
                if (k <= 0) break;
            }
        }
        return res;
    }
    public double eucDist(int x1, int y1, int x2, int y2) {
        int d1 = x1-x2;
        int d2 = y1-y2;
        return Math.sqrt(d1*d1 + d2*d2);
    }
}
