class Solution {
public:
    bool validTicTacToe(vector<string>& board) {
        int turn = 0;
        bool xWin = false, oWin = false;
        vector<int> rows(3, 0), cols(3, 0);
        int diag = 0, rdiag = 0;
        
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (board[i][j] == 'X') {
                    turn++;
                    rows[i]++;
                    cols[j]++;
                    if (i == j) diag++;
                    if (i + j == 2) rdiag++;
                }
                
                if (board[i][j] == 'O') {
                    turn--;
                    rows[i]--;
                    cols[j]--;
                    if (i == j) diag--;
                    if (i + j == 2) rdiag--;
                }
            }
        }
        
        xWin = find(rows.begin(), rows.end(), 3) != rows.end() ||
               find(cols.begin(), cols.end(), 3) != cols.end() ||
               diag == 3 || rdiag == 3;
        
        oWin = find(rows.begin(), rows.end(), -3) != rows.end() ||
               find(cols.begin(), cols.end(), -3) != cols.end() ||
               diag == -3 || rdiag == -3;
        
        if (xWin && turn == 0 || oWin && turn == 1) return false;
        return (turn == 0 || turn == 1) && (!xWin || !oWin);
    }
};