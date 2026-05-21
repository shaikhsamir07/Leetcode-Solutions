class Solution {
public:
    vector<int> findSmallestSetOfVertices(
        int n,
        vector<vector<int>>& edges) {

        vector<int> indegree(n, 0);

        // Count incoming edges
        for (auto& edge : edges) {

            int to = edge[1];

            indegree[to]++;
        }

        vector<int> result;

        // Nodes with indegree 0
        for (int i = 0; i < n; i++) {

            if (indegree[i] == 0) {
                result.push_back(i);
            }
        }

        return result;
    }
};