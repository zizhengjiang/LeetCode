class Solution {
    public boolean validTicTacToe(String[] board) {
        int turn = 0;
        boolean xWin = false, oWin = false;
        int[] rows = new int[3], cols = new int[3];
        int diag = 0, rdiag = 0;
        
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (board[i].charAt(j) == 'X') {
                    turn++;
                    rows[i]++;
                    cols[j]++;
                    if (i == j) diag++;
                    if (i + j == 2) rdiag++;
                }
                
                if (board[i].charAt(j) == 'O') {
                    turn--;
                    rows[i]--;
                    cols[j]--;
                    if (i == j) diag--;
                    if (i + j == 2) rdiag--;
                }
            }
        }
        
        xWin = rows[0] == 3 || rows[1] == 3 || rows[2] == 3 || 
               cols[0] == 3 || cols[1] == 3 || cols[2] == 3 || 
               diag == 3 || rdiag == 3;
        oWin = rows[0] == -3 || rows[1] == -3 || rows[2] == -3 || 
               cols[0] == -3 || cols[1] == -3 || cols[2] == -3 || 
               diag == -3 || rdiag == -3;
        
        if (xWin && turn == 0 || oWin && turn == 1) return false;
        return (turn == 0 || turn == 1) && (!xWin || !oWin);
        
    }
}