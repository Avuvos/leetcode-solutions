class Solution {
        public boolean checkValid(int[][] matrix) {
            int n = matrix.length;
        for (int i = 0; i < n; i++) {
            boolean[] seen = new boolean[n + 1];
            seen[0] = true;
            for (int j = 0; j < n; j++) {
                seen[matrix[i][j]] = true;
            }
            Stream<Boolean> stream = IntStream.range(0, seen.length).mapToObj(idx -> seen[idx]);
            if (!(stream.allMatch(x -> x))) {
                return false;
            }
        }

        for (int i = 0; i < n; i++) {
            boolean[] seen = new boolean[n + 1];
            seen[0] = true;
            for (int j = 0; j < n; j++) {
                seen[matrix[j][i]] = true;
            }
            Stream<Boolean> stream = IntStream.range(0, seen.length).mapToObj(idx -> seen[idx]);
            if (!(stream.allMatch(x -> x))) {
                return false;
            }
        }
        return true;
        }
}
