class Solution {
public:
    bool canFinish(int numCourses,
                   vector<vector<int>>& prerequisites) {

        vector<vector<int>> graph(numCourses);
        vector<int> indegree(numCourses, 0);

        // Build graph
        for (auto& pre : prerequisites) {

            int course = pre[0];
            int prerequisite = pre[1];

            graph[prerequisite].push_back(course);

            indegree[course]++;
        }

        queue<int> q;

        // Push nodes with indegree 0
        for (int i = 0; i < numCourses; i++) {

            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        int completed = 0;

        while (!q.empty()) {

            int node = q.front();
            q.pop();

            completed++;

            for (int neighbor : graph[node]) {

                indegree[neighbor]--;

                if (indegree[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        }

        return completed == numCourses;
    }
};