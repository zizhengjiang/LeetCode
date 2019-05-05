class TicTacToe {
    vector<int> rows, cols;
    int diagonal, rdiagonal;
public:
    /** Initialize your data structure here. */
    TicTacToe(int n) {
        rows = vector<int>(n, 0);
        cols = vector<int>(n, 0);
        diagonal = 0;
        rdiagonal = 0;
    }
    
    /** Player {player} makes a move at ({row}, {col}).
        @param row The row of the board.
        @param col The column of the board.
        @param player The player, can be either 1 or 2.
        @return The current winning condition, can be either:
                0: No one wins.
                1: Player 1 wins.
                2: Player 2 wins. */
    int move(int row, int col, int player) {
        int toAdd = player == 1 ? 1 : -1;
        rows[row] += toAdd;
        cols[col] += toAdd;
        if (row == col) diagonal += toAdd;
        if (row + col == rows.size() - 1) rdiagonal += toAdd;
        
        int s = rows.size();
        if (abs(rows[row]) == s || abs(cols[col]) == s ||
            abs(diagonal) == s || abs(rdiagonal) == s) return player;
        return 0;
    }
};

/**
 * Your TicTacToe object will be instantiated and called as such:
 * TicTacToe* obj = new TicTacToe(n);
 * int param_1 = obj->move(row,col,player);
 */