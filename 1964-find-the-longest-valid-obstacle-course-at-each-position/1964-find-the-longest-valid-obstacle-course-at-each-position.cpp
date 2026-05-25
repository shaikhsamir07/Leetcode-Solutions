class Solution {
public:
    vector<int> longestObstacleCourseAtEachPosition(vector<int>& obstacles) {
        vector<int> lis;
        vector<int> ans;

        for (int x : obstacles) {

            auto it = upper_bound(lis.begin(), lis.end(), x);

            int pos = it - lis.begin();

            if (it == lis.end()) {
                lis.push_back(x);
            } else {
                *it = x;
            }

            ans.push_back(pos + 1);
        }

        return ans;
    }
};