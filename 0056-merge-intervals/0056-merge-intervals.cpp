class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;

        // Sort intervals by starting time
        sort(intervals.begin(), intervals.end());

        for (auto interval : intervals) {

            // If no overlap, add new interval
            if (ans.empty() || ans.back()[1] < interval[0]) {
                ans.push_back(interval);
            }
            else {
                // Merge intervals
                ans.back()[1] = max(ans.back()[1], interval[1]);
            }
        }

        return ans;
    }
};