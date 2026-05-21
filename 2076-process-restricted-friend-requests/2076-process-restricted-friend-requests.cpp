class Solution {
public:

    vector<int> parent;

    int find(int x) {

        if (parent[x] == x) {
            return x;
        }

        return parent[x] =
               find(parent[x]);
    }

    void unite(int x, int y) {

        int px = find(x);
        int py = find(y);

        if (px != py) {
            parent[px] = py;
        }
    }

    vector<bool> friendRequests(
        int n,
        vector<vector<int>>& restrictions,
        vector<vector<int>>& requests) {

        parent.resize(n);

        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }

        vector<bool> result;

        for (auto& req : requests) {

            int u = req[0];
            int v = req[1];

            int pu = find(u);
            int pv = find(v);

            bool possible = true;

            // Check all restrictions
            for (auto& r : restrictions) {

                int x = find(r[0]);
                int y = find(r[1]);

                // Restriction violated
                if ((pu == x && pv == y) ||
                    (pu == y && pv == x)) {

                    possible = false;
                    break;
                }
            }

            if (possible) {

                unite(u, v);
                result.push_back(true);
            }
            else {

                result.push_back(false);
            }
        }

        return result;
    }
};