class Solution {
public:
vector<vector<string>> result;

    void backtrack(int row, int n, vector<string>& board, vector<bool>& cols, vector<bool>& diag1, vector<bool>& diag2) {
        // Base case: All queens are placed successfully, save the board state
        if (row == n) {
            result.push_back(board);
            return;
        }

        for (int col = 0; col < n; col++) {
            // Check if the current column or diagonals are under attack
            if (cols[col] || diag1[row + col] || diag2[row - col + n]) {
                continue;
            }

            // Place the queen
            board[row][col] = 'Q';
            cols[col] = diag1[row + col] = diag2[row - col + n] = true;

            // Move to the next row
            backtrack(row + 1, n, board, cols, diag1, diag2);

            // Backtrack: Remove the queen and restore states
            board[row][col] = '.';
            cols[col] = diag1[row + col] = diag2[row - col + n] = false;
        }
    }


    vector<vector<string>> solveNQueens(int n) {
        result.clear();
        
        // Initialize an empty board with '.'
        vector<string> board(n, string(n, '.'));
        
        // Lookup vectors to track unsafe paths in O(1) time
        vector<bool> cols(n, false);
        vector<bool> diag1(2 * n, false); // top-right to bottom-left (row + col)
        vector<bool> diag2(2 * n, false); // top-left to bottom-right (row - col + n)

        backtrack(0, n, board, cols, diag1, diag2);
        
        return result;
    }
};