class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {

        if (source == target)
            return 0;

        unordered_map<int, vector<int>> stopToBus;

        int n = routes.size();

        for (int bus = 0; bus < n; bus++) {
            for (int stop : routes[bus]) {
                stopToBus[stop].push_back(bus);
            }
        }

        queue<pair<int,int>> q;
        q.push({source, 0});

        unordered_set<int> visitedStops;
        unordered_set<int> visitedBus;

        visitedStops.insert(source);

        while (!q.empty()) {

            auto [stop, busesTaken] = q.front();
            q.pop();

            for (int bus : stopToBus[stop]) {

                if (visitedBus.count(bus))
                    continue;

                visitedBus.insert(bus);

                for (int nextStop : routes[bus]) {

                    if (nextStop == target)
                        return busesTaken + 1;

                    if (!visitedStops.count(nextStop)) {

                        visitedStops.insert(nextStop);

                        q.push({nextStop, busesTaken + 1});
                    }
                }
            }
        }

        return -1;
    }
};