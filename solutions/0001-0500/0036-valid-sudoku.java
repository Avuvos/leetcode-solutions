class Solution {
    public boolean isValidSudoku(char[][] board) {
        int N = 9;
        Set<String> seen = new HashSet<String>();
        
        for (int i=0; i<N; i++){
            for (int j=0; j<N; j++) {
                char num = board[i][j];
                if (num != '.') {
                    if (!seen.add(num + " in row " + i) ||
                        !seen.add(num + " in col " + j) || 
                        !seen.add(num + " in block " + i/3 + "-" +  j/3))
                        return false;
                }
            }
        }
        return true;
    }
}
