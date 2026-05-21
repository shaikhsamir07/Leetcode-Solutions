class Solution {
public:
    vector<int> shortestAlternatingPaths(
        int n,
        vector<vector<int>>& redEdges,
        vector<vector<int>>& blueEdges) {

        vector<pair<int,int>> adj[100];

        // color: 0 = red, 1 = blue

        for (auto &e : redEdges) {
            adj[e[0]].push_back({e[1], 0});
        }

        for (auto &e : blueEdges) {
            adj[e[0]].push_back({e[1], 1});
        }

        vector<vector<int>> vis(n, vector<int>(2, 0));

        vector<int> ans(n, -1);

        queue<pair<int,int>> q;

        q.push({0, -1});

        int dist = 0;

        while (!q.empty()) {

            int sz = q.size();

            while (sz--) {

                auto [node, prevColor] = q.front();
                q.pop();

                if (ans[node] == -1)
                    ans[node] = dist;

                for (auto &[nei, color] : adj[node]) {

                    if (color != prevColor && !vis[nei][color]) {

                        vis[nei][color] = 1;

                        q.push({nei, color});
                    }
                }
            }

            dist++;
        }

        return ans;
    }
};