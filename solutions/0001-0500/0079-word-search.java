class Solution {
    public boolean exist(char[][] board, String word) {
        
        for (int i=0; i<board.length; i++) {
            for (int j=0; j<board[0].length; j++) {
                if (word.charAt(0) == board[i][j]) {
                    boolean check = dfs(board, word, i, j, 0);
                    if (check) {
                        return true;
                    }
                }   
            }
        }
        return false;
    }
    
    public boolean dfs(char[][] board, String word, int i, int j, int k) {
        if (k >= word.length()) {
            return true;
        }
        if (i >= board.length || i < 0 || j >= board[0].length || j < 0) {
            return false;
        }
        if (board[i][j] != word.charAt(k)) {
            return false;
        }
        char curr = board[i][j];
        board[i][j] = '?';
        boolean up = dfs(board, word, i-1, j, k+1);
        boolean down = dfs(board, word, i+1, j, k+1);
        boolean left = dfs(board, word, i, j+1, k+1);
        boolean right = dfs(board, word, i, j-1, k+1);
        board[i][j] = curr;
        return up || down || left || right;
    }
    
}
