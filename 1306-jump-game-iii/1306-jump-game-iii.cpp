class Solution {
public:

    bool dfs(vector<int>& arr,
             int index,
             vector<bool>& visited) {

        // Out of bounds or already visited
        if (index < 0 || index >= arr.size() ||
            visited[index]) {
            return false;
        }

        // Found zero
        if (arr[index] == 0) {
            return true;
        }

        visited[index] = true;

        // Jump forward or backward
        return dfs(arr, index + arr[index], visited) ||
               dfs(arr, index - arr[index], visited);
    }

    bool canReach(vector<int>& arr, int start) {

        vector<bool> visited(arr.size(), false);

        return dfs(arr, start, visited);
    }
};