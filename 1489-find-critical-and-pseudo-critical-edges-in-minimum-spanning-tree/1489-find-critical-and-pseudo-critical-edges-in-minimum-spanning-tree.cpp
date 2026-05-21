class DSU {
public:
    vector<int> parent, rank;

    DSU(int n) {
        parent.resize(n);
        rank.resize(n, 0);

        for (int i = 0; i < n; i++)
            parent[i] = i;
    }

    int find(int x) {
        if (parent[x] == x)
            return x;

        return parent[x] = find(parent[x]);
    }

    bool unite(int x, int y) {

        int px = find(x);
        int py = find(y);

        if (px == py)
            return false;

        if (rank[px] < rank[py])
            swap(px, py);

        parent[py] = px;

        if (rank[px] == rank[py])
            rank[px]++;

        return true;
    }
};

class Solution {
public:
    int kruskal(int n,
                vector<vector<int>>& edges,
                int blockEdge,
                int forceEdge) {

        DSU dsu(n);

        int weight = 0;
        int edgesUsed = 0;

        // Force include edge

        if (forceEdge != -1) {

            auto &e = edges[forceEdge];

            if (dsu.unite(e[0], e[1])) {

                weight += e[2];
                edgesUsed++;
            }
        }

        for (int i = 0; i < edges.size(); i++) {

            if (i == blockEdge)
                continue;

            auto &e = edges[i];

            if (dsu.unite(e[0], e[1])) {

                weight += e[2];
                edgesUsed++;
            }
        }

        return (edgesUsed == n - 1) ? weight : INT_MAX;
    }

    vector<vector<int>> findCriticalAndPseudoCriticalEdges(
        int n,
        vector<vector<int>>& edges) {

        int m = edges.size();

        for (int i = 0; i < m; i++) {
            edges[i].push_back(i);
        }

        sort(edges.begin(), edges.end(),
            [](vector<int>& a, vector<int>& b) {
                return a[2] < b[2];
            });

        int mstWeight = kruskal(n, edges, -1, -1);

        vector<int> critical;
        vector<int> pseudo;

        for (int i = 0; i < m; i++) {

            // Check critical

            if (kruskal(n, edges, i, -1) > mstWeight) {

                critical.push_back(edges[i][3]);

            }
            // Check pseudo-critical
            else if (kruskal(n, edges, -1, i) == mstWeight) {

                pseudo.push_back(edges[i][3]);
            }
        }

        return {critical, pseudo};
    }
};