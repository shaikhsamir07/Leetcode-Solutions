class Solution {
public:
    typedef long long ll;
    const ll INF = 1e18;

    vector<ll> dijkstra(int src, vector<vector<pair<int,int>>>& adj, int n) {

        vector<ll> dist(n, INF);

        priority_queue<
            pair<ll,int>,
            vector<pair<ll,int>>,
            greater<pair<ll,int>>
        > pq;

        dist[src] = 0;
        pq.push({0, src});

        while (!pq.empty()) {

            auto [d, node] = pq.top();
            pq.pop();

            if (d > dist[node])
                continue;

            for (auto &[nei, wt] : adj[node]) {

                if (d + wt < dist[nei]) {

                    dist[nei] = d + wt;

                    pq.push({dist[nei], nei});
                }
            }
        }

        return dist;
    }

    long long minimumWeight(
        int n,
        vector<vector<int>>& edges,
        int src1,
        int src2,
        int dest) {

        vector<vector<pair<int,int>>> adj(n), rev(n);

        for (auto &e : edges) {

            int u = e[0];
            int v = e[1];
            int w = e[2];

            adj[u].push_back({v, w});
            rev[v].push_back({u, w});
        }

        vector<ll> d1 = dijkstra(src1, adj, n);
        vector<ll> d2 = dijkstra(src2, adj, n);
        vector<ll> dd = dijkstra(dest, rev, n);

        ll ans = INF;

        for (int i = 0; i < n; i++) {

            if (d1[i] == INF || d2[i] == INF || dd[i] == INF)
                continue;

            ans = min(ans, d1[i] + d2[i] + dd[i]);
        }

        return ans == INF ? -1 : ans;
    }
};