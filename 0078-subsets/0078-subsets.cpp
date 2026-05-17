class Solution {
public:

    vector<vector<int>> ans;

    void backtrack(vector<int>& nums,
                   int index,
                   vector<int>& current) {

        // Store current subset
        ans.push_back(current);

        for (int i = index; i < nums.size(); i++) {

            current.push_back(nums[i]);

            backtrack(nums, i + 1, current);

            // Backtrack
            current.pop_back();
        }
    }

    vector<vector<int>> subsets(vector<int>& nums) {

        vector<int> current;

        backtrack(nums, 0, current);

        return ans;
    }
};