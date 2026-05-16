class Solution {
public:
    int changes = 0;

    void dfs(int node, int parent,
             vector<vector<pair<int,int>>>& adj) {

        for (auto &it : adj[node]) {
            int nextNode = it.first;
            int needsChange = it.second;

            if (nextNode == parent) continue;

            // If edge is going away from 0, reverse it
            changes += needsChange;

            dfs(nextNode, node, adj);
        }
    }

    int minReorder(int n, vector<vector<int>>& connections) {
        
        vector<vector<pair<int,int>>> adj(n);

        for (auto &edge : connections) {
            int u = edge[0];
            int v = edge[1];

            // Original direction u -> v
            adj[u].push_back({v, 1});

            // Reverse direction v -> u
            adj[v].push_back({u, 0});
        }

        dfs(0, -1, adj);

        return changes;
    }
};