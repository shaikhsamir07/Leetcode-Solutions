class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {

        int n = points.size();

        vector<int> minDist(n, INT_MAX);
        vector<int> vis(n, 0);

        minDist[0] = 0;

        int cost = 0;

        for (int i = 0; i < n; i++) {

            int u = -1;

            for (int j = 0; j < n; j++) {

                if (!vis[j] &&
                    (u == -1 || minDist[j] < minDist[u])) {

                    u = j;
                }
            }

            vis[u] = 1;

            cost += minDist[u];

            for (int v = 0; v < n; v++) {

                if (!vis[v]) {

                    int dist = abs(points[u][0] - points[v][0]) +
                               abs(points[u][1] - points[v][1]);

                    minDist[v] = min(minDist[v], dist);
                }
            }
        }

        return cost;
    }
};