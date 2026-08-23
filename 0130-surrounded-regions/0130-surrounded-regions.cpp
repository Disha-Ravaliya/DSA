class Solution {
public:

    void dfs(int i, int j,
             int n, int m,
             vector<vector<char>>& board) {

        // boundary check
        if(i < 0 || j < 0 || i >= n || j >= m) {
            return;
        }

        // stop if not O
        if(board[i][j] != 'O') {
            return;
        }

        // mark safe
        board[i][j] = 'S';

        
        dfs(i-1, j, n, m, board); // top
        dfs(i, j+1, n, m, board); // right
        dfs(i+1, j, n, m, board); // bottom
        dfs(i, j-1, n, m, board); // left
    }

    void solve(vector<vector<char>>& board) {

        int n = board.size();
        int m = board[0].size();

        // top row
        for(int j = 0; j < m; j++) {

            if(board[0][j] == 'O') {
                dfs(0, j, n, m, board);
            }
        }

        // bottom row
        for(int j = 0; j < m; j++) {

            if(board[n-1][j] == 'O') {
                dfs(n-1, j, n, m, board);
            }
        }

        // left column
        for(int i = 0; i < n; i++) {

            if(board[i][0] == 'O') {
                dfs(i, 0, n, m, board);
            }
        }

        // right column
        for(int i = 0; i < n; i++) {

            if(board[i][m-1] == 'O') {
                dfs(i, m-1, n, m, board);
            }
        }

        // final traversal
        for(int i = 0; i < n; i++) {

            for(int j = 0; j < m; j++) {

                // trapped region means inmiddle any o then it x
                if(board[i][j] == 'O') {
                    board[i][j] = 'X';
                }

                // safe region
                else if(board[i][j] == 'S') {
                    board[i][j] = 'O';
                }
            }
        }
    }
};