class Solution {
public:
    vector<int> leftmostBuildingQueries(vector<int>& heights,
                                        vector<vector<int>>& queries) {

        int n = heights.size();

        vector<int> ans(queries.size(), -1);

        vector<vector<pair<int,int>>> pending(n);

        for (int i = 0; i < queries.size(); i++) {

            int a = queries[i][0];
            int b = queries[i][1];

            if (a > b)
                swap(a, b);

            if (a == b || heights[a] < heights[b]) {

                ans[i] = b;

            } else {

                pending[b].push_back({heights[a], i});
            }
        }

        priority_queue<
            pair<int,int>,
            vector<pair<int,int>>,
            greater<pair<int,int>>
        > pq;

        for (int i = 0; i < n; i++) {

            for (auto &[h, idx] : pending[i]) {
                pq.push({h, idx});
            }

            while (!pq.empty() &&
                   pq.top().first < heights[i]) {

                ans[pq.top().second] = i;
                pq.pop();
            }
        }

        return ans;
    }
};