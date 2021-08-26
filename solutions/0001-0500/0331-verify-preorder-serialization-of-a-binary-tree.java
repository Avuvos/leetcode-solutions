class Solution {
    public boolean isValidSerialization(String preorder) {
        String [] nodes = preorder.split(",");
        int edges = 1;
        for (int i=0; i < nodes.length; i++) {
            edges -= 1;
            if (edges < 0)
                return false;
            if (!nodes[i].equals("#"))
                edges += 2;
        }
        return edges == 0;
    }
}
