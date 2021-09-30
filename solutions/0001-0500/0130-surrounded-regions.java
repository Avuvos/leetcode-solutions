class Solution {
    public void solve(char[][] board) {
        boolean [][] visited = new boolean[board.length + 1][board[0].length + 1];
        for (int i=0; i<board.length; i++) {
            for (int j=0; j<board[0].length; j++) {
                if (board[i][j] == 'X') {
                    visited[i][j] = true;
                }
                if (i == 0 || j == 0 || i == board.length - 1 
                    || j == board[0].length-1) {
                    if (board[i][j] == 'O') {
                        dfs(board, i, j, visited);
                    }
                }  
            }
        }
        for (int i=0; i<board.length; i++) {
            for (int j=0; j<board[0].length; j++) {
                if (board[i][j] == 'O' && !visited[i][j])  {
                    board[i][j] = 'X';
                }
            }
        }   
    }
    
    //check which cells shouldnt be painted and mark them as visited
    public void dfs(char[][] board, int i, int j, boolean visited[][]) {
        if (i<0 || j<0 || i>=board.length || j>=board[0].length || visited[i][j]) {
            return;
        }
        if (board[i][j] == 'X') {
            return;
        }
        visited[i][j] = true;
        dfs(board, i+1, j, visited);
        dfs(board, i-1, j, visited);
        dfs(board, i, j+1, visited);
        dfs(board, i,  j-1, visited);
    }
}
