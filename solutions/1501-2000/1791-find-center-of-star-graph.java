class Solution {
    public int findCenter(int[][] edges) {
        int first = edges[0][0];
        int second = edges[0][1];
        
        
        for (int i=1; i<edges.length; i++) {
            if (edges[i][0] != first && edges[i][1] != first) {
                return second;
            }
            else {
                return first;
            }
            
        }
        return first;
    }
}
