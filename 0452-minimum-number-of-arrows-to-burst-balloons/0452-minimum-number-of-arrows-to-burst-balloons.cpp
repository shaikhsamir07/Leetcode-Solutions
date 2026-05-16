class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {

        if (points.empty()) {
            return 0;
        }

        // Sort by ending coordinate
        sort(points.begin(), points.end(),
            [](vector<int>& a, vector<int>& b) {
                return (long long)a[1] < (long long)b[1];
            });

        int arrows = 1;

        long long end = points[0][1];

        for (int i = 1; i < points.size(); i++) {

            // Need new arrow
            if (points[i][0] > end) {
                arrows++;
                end = points[i][1];
            }
        }

        return arrows;
    }
};