class Solution {
public:

    vector<vector<string>> ans;

    bool isSafe(vector<string>& board,
                int row,
                int col,
                int n) {

        // Check upper-left diagonal
        int r = row, c = col;
        while (r >= 0 && c >= 0) {
            if (board[r][c] == 'Q') {
                return false;
            }
            r--;
            c--;
        }

        // Check same column upward
        r = row;
        c = col;
        while (r >= 0) {
            if (board[r][c] == 'Q') {
                return false;
            }
            r--;
        }

        // Check upper-right diagonal
        r = row;
        c = col;
        while (r >= 0 && c < n) {
            if (board[r][c] == 'Q') {
                return false;
            }
            r--;
            c++;
        }

        return true;
    }

    void backtrack(vector<string>& board,
                   int row,
                   int n) {

        // Valid board found
        if (row == n) {
            ans.push_back(board);
            return;
        }

        for (int col = 0; col < n; col++) {

            if (isSafe(board, row, col, n)) {

                board[row][col] = 'Q';

                backtrack(board, row + 1, n);

                // Backtrack
                board[row][col] = '.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {

        vector<string> board(n, string(n, '.'));

        backtrack(board, 0, n);

        return ans;
    }
};