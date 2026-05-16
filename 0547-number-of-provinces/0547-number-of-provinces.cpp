class Solution {
public:
    void dfs(int city, vector<vector<int>>& isConnected, vector<bool>& visited) {
        visited[city] = true;

        for (int nextCity = 0; nextCity < isConnected.size(); nextCity++) {
            if (isConnected[city][nextCity] == 1 && !visited[nextCity]) {
                dfs(nextCity, isConnected, visited);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();

        vector<bool> visited(n, false);

        int provinces = 0;

        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                dfs(i, isConnected, visited);
                provinces++;
            }
        }

        return provinces;
    }
};