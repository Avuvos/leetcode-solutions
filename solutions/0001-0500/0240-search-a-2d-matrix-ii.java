class Solution {
    public boolean searchMatrix(int[][] matrix, int target) {
        int n = matrix.length;
        if (n == 1 && matrix[0].length == 1 && matrix[0][0] != target) return false;
        int x = 0;
        int y = matrix[0].length-1;
    
        while (x < n && y >= 0) {
            
            if (matrix[x][y] == target) return true;
            
            else if (matrix[x][y] > target) y--;
            
            else x++;
            
        }
        
        return false;
    }
}
