class Solution {
public:
    vector<vector<int>> ans;

    void dfs(int node, vector<vector<int>>& graph, vector<int>& path) {
        
        int n = graph.size();

        if (node == n - 1) {
            ans.push_back(path);
            return;
        }

        for (int nei : graph[node]) {
            path.push_back(nei);

            dfs(nei, graph, path);

            path.pop_back();
        }
    }

    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        
        vector<int> path;
        path.push_back(0);

        dfs(0, graph, path);

        return ans;
    }
};