class Solution {
    int res = 0;
    public int maximalPathQuality(int[] values, int[][] edges, int maxTime) {
        Map<Integer, List<int[]>> map = new HashMap<>();
        for (int i = 0; i < values.length; i++) map.put(i, new LinkedList<>());
        for (int[] e: edges) {
            int u = e[0], v = e[1], t = e[2];
            map.get(u).add(new int[]{v, t});
            map.get(v).add(new int[]{u, t});
        }
        int[] visited = new int [values.length];
        visited[0] = 1;
        dfs(0, 0, values, map, maxTime, values[0], visited);
        return res;
    }
    public void dfs(int node, int time, int[] vals, Map<Integer, List<int[]>> map, int maxTime, int quality, int[]vis) {
        if (node == 0) res = Math.max(res, quality);
        for (int i = 0; i < map.get(node).size(); i++) {
            int t = map.get(node).get(i)[1];
            int nei = map.get(node).get(i)[0];
            if (time + t <= maxTime) {
                if (vis[nei] == 0) {
                    vis[nei] = 1;
                    dfs(nei, time + t, vals, map, maxTime, quality + vals[nei], vis);
                    vis[nei] = 0;
                }
                else{
                    dfs(nei, time + t, vals, map, maxTime, quality, vis);
                }
            }
        }
    }
}
