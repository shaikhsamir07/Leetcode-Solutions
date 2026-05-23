class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& heights) {
        int n = heights.size();

        vector<int> ans(n, 0);
        stack<int> st;

        // Traverse from right to left
        for (int i = n - 1; i >= 0; i--) {

            // Count shorter people visible
            while (!st.empty() && heights[i] > st.top()) {
                ans[i]++;
                st.pop();
            }

            // If someone taller exists, they are also visible
            if (!st.empty()) {
                ans[i]++;
            }

            st.push(heights[i]);
        }

        return ans;
    }
};