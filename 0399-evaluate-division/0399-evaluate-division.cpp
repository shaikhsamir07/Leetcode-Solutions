class Solution {
public:
    
    bool dfs(string src, string dest,
             unordered_map<string, vector<pair<string,double>>>& adj,
             unordered_set<string>& visited,
             double& product) {

        if (visited.count(src)) return false;

        visited.insert(src);

        // Destination found
        if (src == dest) {
            return true;
        }

        for (auto &neighbor : adj[src]) {
            string next = neighbor.first;
            double value = neighbor.second;

            product *= value;

            if (dfs(next, dest, adj, visited, product)) {
                return true;
            }

            // Backtrack
            product /= value;
        }

        return false;
    }

    vector<double> calcEquation(vector<vector<string>>& equations,
                                vector<double>& values,
                                vector<vector<string>>& queries) {

        unordered_map<string, vector<pair<string,double>>> adj;

        // Build graph
        for (int i = 0; i < equations.size(); i++) {
            string a = equations[i][0];
            string b = equations[i][1];
            double val = values[i];

            adj[a].push_back({b, val});
            adj[b].push_back({a, 1.0 / val});
        }

        vector<double> ans;

        for (auto &q : queries) {
            string src = q[0];
            string dest = q[1];

            // Variable not present
            if (adj.find(src) == adj.end() ||
                adj.find(dest) == adj.end()) {
                ans.push_back(-1.0);
                continue;
            }

            unordered_set<string> visited;
            double product = 1.0;

            if (dfs(src, dest, adj, visited, product)) {
                ans.push_back(product);
            } else {
                ans.push_back(-1.0);
            }
        }

        return ans;
    }
};