class Solution {
    public int[][] floodFill(int[][] image, int sr, int sc, int newColor) {
        int color = image[sr][sc];
        if (color != newColor) 
            BFS(image, sr, sc, color, newColor);
        return image;
    }
    
    public void BFS(int[][] image, int i, int j, int color, int newColor) {
        Queue<int[]> q = new LinkedList<>();
        q.offer(new int []{i, j});
        while (!q.isEmpty()) {
            int size = q.size();
            for (int k=0; k<size; k++) {
                int[] curr = q.poll();
                int x = curr[0], y = curr[1];
                if (image[x][y] == color) { 
                    image[x][y] = newColor;
                    if (x > 0) q.offer(new int[] {x-1, y});
                    if (x < image.length-1) q.offer(new int[] {x+1, y});
                    if (y > 0) q.offer(new int[] {x, y-1});
                    if (y < image[0].length-1) q.offer(new int[] {x, y+1});
                }
            }
        }
    }
}
