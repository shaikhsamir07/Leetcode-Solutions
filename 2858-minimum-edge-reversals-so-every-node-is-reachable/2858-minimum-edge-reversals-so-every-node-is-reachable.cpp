class Solution {
public:
    vector<vector<pair<int,int>>> graph;
    vector<int> ans;

    // DFS to calculate reversals needed from node 0
    int dfs1(int node, int parent) {
        int changes = 0;

        for (auto &[next, cost] : graph[node]) {
            if (next == parent) continue;

            changes += cost + dfs1(next, node);
        }

        return changes;
    }

    // DFS to calculate answers for all nodes
    void dfs2(int node, int parent) {

        for (auto &[next, cost] : graph[node]) {
            if (next == parent) continue;

            // If edge node -> next exists
            // moving root to next increases/decreases reversals
            if (cost == 0) {
                ans[next] = ans[node] + 1;
            } else {
                ans[next] = ans[node] - 1;
            }

            dfs2(next, node);
        }
    }

    vector<int> minEdgeReversals(int n, vector<vector<int>>& edges) {

        graph.resize(n);
        ans.resize(n);

        // Build graph
        for (auto &e : edges) {
            int u = e[0];
            int v = e[1];

            // Original direction u -> v
            graph[u].push_back({v, 0});

            // Reverse direction v -> u
            graph[v].push_back({u, 1});
        }

        // Calculate answer for node 0
        ans[0] = dfs1(0, -1);

        // Re-rooting DFS
        dfs2(0, -1);

        return ans;
    }
};