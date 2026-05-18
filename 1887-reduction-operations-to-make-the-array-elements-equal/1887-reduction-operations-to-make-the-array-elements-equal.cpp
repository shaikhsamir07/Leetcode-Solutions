class Solution {
public:
    int reductionOperations(vector<int>& nums) {

        sort(nums.begin(), nums.end());

        int operations = 0;
        int count = 0;

        for (int i = 1; i < nums.size(); i++) {

            // New larger element found
            if (nums[i] != nums[i - 1]) {
                count++;
            }

            operations += count;
        }

        return operations;
    }
};