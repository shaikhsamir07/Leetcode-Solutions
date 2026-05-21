class Solution {
public:
    int ans = 0;

    void dfs(int node,
             int time,
             int score,
             vector<int>& values,
             vector<vector<pair<int,int>>>& adj,
             vector<int>& vis,
             int maxTime) {

        if (time > maxTime) return;

        if (node == 0)
            ans = max(ans, score);

        for (auto &[nei, t] : adj[node]) {
            bool firstVisit = (vis[nei] == 0);

            vis[nei]++;

            dfs(nei,
                time + t,
                score + (firstVisit ? values[nei] : 0),
                values,
                adj,
                vis,
                maxTime);

            vis[nei]--;
        }
    }

    int maximalPathQuality(vector<int>& values, vector<vector<int>>& edges, int maxTime) {

        int n = values.size();

        vector<vector<pair<int,int>>> adj(n);

        for (auto &e : edges) {
            int u = e[0];
            int v = e[1];
            int t = e[2];

            adj[u].push_back({v, t});
            adj[v].push_back({u, t});
        }

        vector<int> vis(n, 0);

        vis[0] = 1;

        dfs(0, 0, values[0], values, adj, vis, maxTime);

        return ans;
    }
};