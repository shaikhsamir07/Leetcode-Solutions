class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {

        vector<vector<int>> dist(n, vector<int>(n, 1e9));

        for (int i = 0; i < n; i++) {
            dist[i][i] = 0;
        }

        for (auto &e : edges) {

            int u = e[0];
            int v = e[1];
            int w = e[2];

            dist[u][v] = w;
            dist[v][u] = w;
        }

        // Floyd Warshall

        for (int via = 0; via < n; via++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {

                    if (dist[i][via] == 1e9 || dist[via][j] == 1e9)
                        continue;

                    dist[i][j] = min(dist[i][j],
                                     dist[i][via] + dist[via][j]);
                }
            }
        }

        int city = -1;
        int minReachable = INT_MAX;

        for (int i = 0; i < n; i++) {

            int cnt = 0;

            for (int j = 0; j < n; j++) {

                if (i != j && dist[i][j] <= distanceThreshold)
                    cnt++;
            }

            if (cnt <= minReachable) {
                minReachable = cnt;
                city = i;
            }
        }

        return city;
    }
};