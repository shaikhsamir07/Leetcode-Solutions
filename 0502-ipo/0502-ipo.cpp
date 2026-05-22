class Solution {
public:

    int findMaximizedCapital(int k,
                             int w,
                             vector<int>& profits,
                             vector<int>& capital) {

        int n = profits.size();

        vector<pair<int, int>> projects;

        for (int i = 0; i < n; i++) {
            projects.push_back({capital[i], profits[i]});
        }

        sort(projects.begin(), projects.end());

        priority_queue<int> maxHeap;

        int i = 0;

        while (k--) {

            // Add all affordable projects
            while (i < n && projects[i].first <= w) {

                maxHeap.push(projects[i].second);
                i++;
            }

            // No project can be done
            if (maxHeap.empty())
                break;

            // Pick most profitable project
            w += maxHeap.top();
            maxHeap.pop();
        }

        return w;
    }
};