class Solution {
    public List<List<Integer>> highestRankedKItems(int[][] grid, int[] pricing, int[] start, int k) {
        
        //initiallize DS
        int n = grid.length, m = grid[0].length;
        Queue<int[]> queue = new LinkedList<>(); //will save positions (i, j)
        int[][] distances = new int[n][m];
        
        //PQ Comparator
        PriorityQueue<int[]> highestRankedQueue  = new PriorityQueue<>(new Comparator<int[]>() {
            @Override
            public int compare(int[] o1, int[] o2) {
                int x1 = o1[0], y1 = o1[1], x2 = o2[0], y2 = o2[1];
                int distDiff = distances[x1][y1] - distances[x2][y2];
                if (distDiff != 0) {
                    return -distDiff;
                }
                int priceDiff = grid[x1][y1] - grid[x2][y2];
                if (priceDiff != 0) {
                    return -priceDiff;
                }
                if (x1 != x2) {
                    return x2 - x1;
                }
                return y2 - y1;
            }
        });
        
        //BFS
        boolean[][] visited = new boolean[n][m];
        queue.offer(start);
        int steps = 0;
        while (!queue.isEmpty()) {
            int size = queue.size();
            for (int i = 0; i < size; i++) {
                int[] pos = queue.poll();
                int x = pos[0], y = pos[1];
                int currPrice = grid[x][y];
                if (currPrice == 0 || visited[x][y]) continue;
                visited[x][y] = true;
                distances[x][y] = steps;
                if (currPrice != 1 && (pricing[0] <= currPrice) && (currPrice <= pricing[1])) {
                    highestRankedQueue.offer(pos);
                    if (highestRankedQueue.size() >= k + 1) {
                        highestRankedQueue.poll();
                    }
                }
                if (x + 1 < n) queue.offer(new int[]{x + 1, y});
                if (x - 1 >= 0) queue.offer(new int[]{x - 1, y});
                if (y + 1 < m) queue.offer(new int[]{x, y + 1});
                if (y - 1 >= 0) queue.offer(new int[]{x, y - 1});
            }
            steps++;
        }
        
        //get result
        List<List<Integer>> res = new ArrayList<>();
        while (!highestRankedQueue.isEmpty() && res.size() != k) {
            int[] pos = highestRankedQueue.poll();
            res.add(new ArrayList<>(Arrays.asList(pos[0], pos[1])));
        }
        Collections.reverse(res);
        return res;
    }
}
