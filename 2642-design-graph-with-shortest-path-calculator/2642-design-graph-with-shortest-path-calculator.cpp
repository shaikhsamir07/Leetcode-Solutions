class Graph {
public:
    int n;
    vector<vector<pair<int,int>>> adj;

    Graph(int n, vector<vector<int>>& edges) {

        this->n = n;

        adj.resize(n);

        for (auto &e : edges) {

            int u = e[0];
            int v = e[1];
            int w = e[2];

            adj[u].push_back({v, w});
        }
    }

    void addEdge(vector<int> edge) {

        int u = edge[0];
        int v = edge[1];
        int w = edge[2];

        adj[u].push_back({v, w});
    }

    int shortestPath(int node1, int node2) {

        vector<int> dist(n, INT_MAX);

        priority_queue<
            pair<int,int>,
            vector<pair<int,int>>,
            greater<pair<int,int>>
        > pq;

        dist[node1] = 0;

        pq.push({0, node1});

        while (!pq.empty()) {

            auto [d, node] = pq.top();
            pq.pop();

            if (node == node2)
                return d;

            if (d > dist[node])
                continue;

            for (auto &[nei, wt] : adj[node]) {

                if (d + wt < dist[nei]) {

                    dist[nei] = d + wt;

                    pq.push({dist[nei], nei});
                }
            }
        }

        return -1;
    }
};

/**
 * Your Graph object will be instantiated and called as such:
 * Graph* obj = new Graph(n, edges);
 * obj->addEdge(edge);
 * int param_2 = obj->shortestPath(node1,node2);
 */