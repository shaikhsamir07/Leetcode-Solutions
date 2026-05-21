class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {

        int m = board.size();
        int n = board[0].size();

        vector<pair<int, int>> directions = {
            {-1, -1}, {-1, 0}, {-1, 1},
            {0, -1},           {0, 1},
            {1, -1},  {1, 0},  {1, 1}
        };

        // First pass: mark transitions
        for (int i = 0; i < m; i++) {

            for (int j = 0; j < n; j++) {

                int liveNeighbors = 0;

                for (auto& d : directions) {

                    int ni = i + d.first;
                    int nj = j + d.second;

                    if (ni >= 0 && ni < m &&
                        nj >= 0 && nj < n &&
                        abs(board[ni][nj]) == 1) {

                        liveNeighbors++;
                    }
                }

                // Live cell dies
                if (board[i][j] == 1 &&
                    (liveNeighbors < 2 ||
                     liveNeighbors > 3)) {

                    board[i][j] = -1;
                }

                // Dead cell becomes live
                if (board[i][j] == 0 &&
                    liveNeighbors == 3) {

                    board[i][j] = 2;
                }
            }
        }

        // Second pass: finalize states
        for (int i = 0; i < m; i++) {

            for (int j = 0; j < n; j++) {

                if (board[i][j] > 0) {
                    board[i][j] = 1;
                }
                else {
                    board[i][j] = 0;
                }
            }
        }
    }
};