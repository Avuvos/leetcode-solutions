class Solution {
    public static void dfsSCC(int node, Map<Integer, List<Integer>> graph, boolean[] visited, int[] cntNodeEdge) {
        visited[node] = true;
        List<Integer> neighbors = graph.getOrDefault(node, new ArrayList<>());
        cntNodeEdge[0]++;
        cntNodeEdge[1] += neighbors.size();
        for (int neigh: neighbors) {
            if (!visited[neigh]) {
                dfsSCC(neigh, graph, visited, cntNodeEdge);
            }
        }
    }

    public static int makeConnected(int n, int[][] connections) {
        //graph setup
        Map<Integer, List<Integer>> graph = new HashMap<>();
        for (int node = 0; node < n; node++) {
            graph.put(node, new ArrayList<>());
        }
        for (int[] con: connections) {
            graph.get(con[0]).add(con[1]);
            graph.get(con[1]).add(con[0]);
        }
        //lets run DFS which will count the "extra edges" for each comp
        int extraEdges = 0;
        int components = 0;
        int[] cntNodeEdge; //node counter, edge counter
        boolean[] visited = new boolean[n];
        for (int node = 0; node < n; node++) {
            if (!visited[node]) {
                cntNodeEdge = new int[2];
                dfsSCC(node, graph, visited, cntNodeEdge);
                extraEdges += Math.max(0,cntNodeEdge[1]/2 - (cntNodeEdge[0] - 1));
                components++;
            }
        }
        return (extraEdges >= components - 1) ? components - 1 : - 1;
    }
}
