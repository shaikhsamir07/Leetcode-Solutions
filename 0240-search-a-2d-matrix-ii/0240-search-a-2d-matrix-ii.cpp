class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix,
                      int target) {

        int rows = matrix.size();
        int cols = matrix[0].size();

        int row = 0;
        int col = cols - 1;

        // Start from top-right corner
        while (row < rows &&
               col >= 0) {

            if (matrix[row][col] == target) {

                return true;
            }

            // Move left
            else if (matrix[row][col] > target) {

                col--;
            }

            // Move down
            else {

                row++;
            }
        }

        return false;
    }
};