class Solution {
    private char [][] board;
    
    public void solveSudoku(char[][] board) {
        this.board = board;
        helper(0, 0);
    }
    public boolean helper(int row, int col) {
        if (col == 9) {
            row += 1;
            col = 0;
        }
        
        if (row == 9) return true;
        
        if (board[row][col] != '.')
            return helper(row, col + 1);
        
        for (char i = '1'; i <= '9'; i++) {
            if (!isValid(board, row, col, i))
                continue;
            board[row][col] = i;
            if (helper(row, col + 1) == true)
                return true;
            board[row][col] = '.';
        }
        return false;
    
    }
    
    public boolean isValid(char[][] board,  int row, int col, char c) {
        for (int i=0; i<9; i++) {
            if (board[i][col] != '.' && board[i][col] == c) return false;
            if (board[row][i] != '.' && board[row][i] == c) return false;
            if (board[3*(row/3)+i/3][3*(col/3)+i%3] != '.' && board[3*(row/3)+i/3][3*(col/3)+i%3] == c) return false;
        }
        return true;
        
    }
}
