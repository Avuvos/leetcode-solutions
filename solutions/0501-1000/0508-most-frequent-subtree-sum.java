/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    Map<Integer, Integer> map = new HashMap<Integer, Integer>();//key = sum, val = freq
    List<Integer> res = new ArrayList<>();
    int bestFreq = 0; //the frequency of the subtree sum that shows up the most
    public int[] findFrequentTreeSum(TreeNode root) {
        dfs(root); 
        for(Map.Entry<Integer, Integer> entry: map.entrySet()) {
            int key = entry.getKey(); 
            int val = entry.getValue();
            if (val == bestFreq) { //if the value matches bestFreq add it to the result
                res.add(key);
            }
        }
        int [] arr = new int [res.size()]; //convert list to array...
        for (int i=0; i<arr.length; i++) {
            arr[i] = res.get(i);
        }
        return arr; 
    }
    
    public int dfs(TreeNode root) { //find the subtree sum of all the nodes
        if (root == null) {
            return 0;
        }
        int leftSum = dfs(root.left);
        int rightSum = dfs(root.right);
        int totalSum = root.val + leftSum +rightSum;
        map.put(totalSum, map.getOrDefault(totalSum, 0) + 1);
        if (map.get(totalSum) > bestFreq) { //update the best frequency each time
            bestFreq = map.get(totalSum);
        }
        return totalSum;
    }
}
