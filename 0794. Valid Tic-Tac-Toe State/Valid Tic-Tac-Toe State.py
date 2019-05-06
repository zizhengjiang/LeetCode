class Solution:
    def validTicTacToe(self, board: List[str]) -> bool:
        first, second = 'X', 'O'
        x_count = sum(row.count(first) for row in board)
        o_count = sum(row.count(second) for row in board)
        
        def win(board: List[str], player: str):
            for i in range(3):
                if all(board[i][j] == player for j in range(3)):
                    return True
                if all(board[j][i] == player for j in range(3)):
                    return True
            return (player == board[0][0] == board[1][1] == board[2][2] or
                    player == board[0][2] == board[1][1] == board[2][0])
        
        if o_count not in {x_count - 1, x_count}:
            return False
        if win(board, first) and x_count - 1 != o_count:
            return False
        if win(board, second) and x_count != o_count:
            return False
        return True