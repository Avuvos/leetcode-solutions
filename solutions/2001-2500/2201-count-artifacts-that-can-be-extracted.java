class Solution {
    public int digArtifacts(int n, int[][] artifacts, int[][] dig) {
        boolean[][] discovered = new boolean[n][n];
        for (int[] d: dig) {
            int x = d[0], y = d[1];
            discovered[x][y] = true;
        }

        int res = 0;
        for (int[] art: artifacts) {
            int r1 = art[0], c1 = art[1], r2 = art[2], c2 = art[3];
            boolean good = true;
            for (int x = r1; x <= r2; x++) {
                for (int y = c1; y <= c2; y++) {
                   if (!discovered[x][y]) {
                       good = false;
                       break;
                   }
                   if (!good) break;
                }
            }
            if (good) res++;
        }
        return res;
    }
}
