class Solution {
public:

    vector<vector<int>> ans;

    void backtrack(vector<int>& nums, int index) {

        // One permutation formed
        if (index == nums.size()) {
            ans.push_back(nums);
            return;
        }

        for (int i = index; i < nums.size(); i++) {

            swap(nums[index], nums[i]);

            backtrack(nums, index + 1);

            // Backtrack
            swap(nums[index], nums[i]);
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {

        backtrack(nums, 0);

        return ans;
    }
};