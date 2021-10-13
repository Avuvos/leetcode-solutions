class Solution {
    public int maxPoints(int[][] points) {
        int res = 0;
        for (int i = 0; i < points.length; i++) {
            Map<String, Integer> map = new HashMap<>(); //point to slope
            int dup = 0, max = 0;
            for (int j = i + 1; j < points.length; j++) {
                int dx = points[i][0] - points[j][0];
                int dy = points[i][1] - points[j][1];
                if (dx == 0 && dy == 0) {
                    dup++;
                    continue;
                }
                int gcd = gcd(dx, dy);
                String point = dx / gcd + "," + dy / gcd;
                map.put(point, map.getOrDefault(point, 0) + 1);
                max = Math.max(max, map.get(point));
            }
            res = Math.max(res, max + dup + 1);
        }
        return res;
    }
    public static int gcd(int a, int b) {
        if (b == 0) return a;
        return gcd(b, a % b);
    }
}
