class Solution {
public:
    int minJumps(vector<int>& arr) {

        int n = arr.size();

        if (n == 1) {
            return 0;
        }

        unordered_map<int, vector<int>> mp;

        // Store indices for each value
        for (int i = 0; i < n; i++) {
            mp[arr[i]].push_back(i);
        }

        queue<int> q;
        vector<bool> visited(n, false);

        q.push(0);
        visited[0] = true;

        int steps = 0;

        while (!q.empty()) {

            int size = q.size();

            while (size--) {

                int index = q.front();
                q.pop();

                // Reached last index
                if (index == n - 1) {
                    return steps;
                }

                // Jump to same value indices
                for (int next : mp[arr[index]]) {

                    if (!visited[next]) {

                        visited[next] = true;
                        q.push(next);
                    }
                }

                // Clear to avoid repeated processing
                mp[arr[index]].clear();

                // Jump to index - 1
                if (index - 1 >= 0 &&
                    !visited[index - 1]) {

                    visited[index - 1] = true;
                    q.push(index - 1);
                }

                // Jump to index + 1
                if (index + 1 < n &&
                    !visited[index + 1]) {

                    visited[index + 1] = true;
                    q.push(index + 1);
                }
            }

            steps++;
        }

        return -1;
    }
};