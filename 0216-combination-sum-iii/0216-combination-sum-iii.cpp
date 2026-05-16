class Solution {
public:

    vector<vector<int>> ans;

    void backtrack(int start,
                   int k,
                   int target,
                   vector<int>& current) {

        // Valid combination found
        if (target == 0 && current.size() == k) {
            ans.push_back(current);
            return;
        }

        // Invalid case
        if (target < 0 || current.size() > k) {
            return;
        }

        for (int i = start; i <= 9; i++) {

            current.push_back(i);

            backtrack(i + 1, k, target - i, current);

            // Backtrack
            current.pop_back();
        }
    }

    vector<vector<int>> combinationSum3(int k, int n) {

        vector<int> current;

        backtrack(1, k, n, current);

        return ans;
    }
};