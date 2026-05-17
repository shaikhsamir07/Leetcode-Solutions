class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {

        int n = nums.size();

        // Place each number at its correct index
        for (int i = 0; i < n; i++) {

            while (nums[i] > 0 &&
                   nums[i] <= n &&
                   nums[i] != nums[nums[i] - 1]) {

                swap(nums[i],
                     nums[nums[i] - 1]);
            }
        }

        // Find first missing positive
        for (int i = 0; i < n; i++) {

            if (nums[i] != i + 1) {

                return i + 1;
            }
        }

        return n + 1;
    }
};