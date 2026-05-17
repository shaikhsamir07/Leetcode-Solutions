class Solution {
public:

    vector<vector<int>> ans;

    void backtrack(vector<int>& candidates,
                   int target,
                   int index,
                   vector<int>& current) {

        // Valid combination found
        if (target == 0) {
            ans.push_back(current);
            return;
        }

        // Out of bounds or target negative
        if (index >= candidates.size() || target < 0) {
            return;
        }

        // Take current number
        current.push_back(candidates[index]);

        backtrack(candidates,
                  target - candidates[index],
                  index,
                  current);

        current.pop_back();

        // Skip current number
        backtrack(candidates,
                  target,
                  index + 1,
                  current);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates,
                                       int target) {

        vector<int> current;

        backtrack(candidates, target, 0, current);

        return ans;
    }
};