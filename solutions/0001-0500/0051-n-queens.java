class Solution {
    public List<List<String>> solveNQueens(int n) {
        List<List<String>> res = new ArrayList<>();
        String [] board = new String[n];
        String s = ".";
        s = s.repeat(n);
        Arrays.fill(board, s);
        dfsQ(res, n, 0, board);
        return res;
    }
    public boolean isValid(String[] board, int x, int y, int n) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i == x || j == y || Math.abs(i - x) == Math.abs(j - y)) {
                    if (board[i].charAt(j) != '.') return false;
                }
            }
        }
        return true;
    }
    public void dfsQ(List<List<String>> res, int QueensLeft, int row, String[] board) {
        if (QueensLeft == 0) {
            List<String> path = new ArrayList<>();
            for (String st: board) {
                path.add(st);
            }
            res.add(path);
        }
        if (row >= board.length) {
            return;
        }
        for (int j = 0; j < board.length; j++) {
            if (isValid(board, row, j, board.length)) {
                String prevRow = board[row];
                String newRow = "";
                for (int k = 0; k < board.length; k++) {
                    if (k == j) newRow += 'Q';
                    else newRow += '.';
                }
                board[row] = newRow;
                dfsQ(res, QueensLeft - 1, row + 1, board);
                board[row] = prevRow;
            }
        }
    }
}
