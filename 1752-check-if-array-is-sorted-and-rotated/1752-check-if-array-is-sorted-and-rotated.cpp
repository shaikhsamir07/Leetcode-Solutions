class Solution {
public:
    bool check(vector<int>& nums) {
        int count = 0;
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            // Compare current element with next element
            if (nums[i] > nums[(i + 1) % n]) {
                count++;
            }
        }

        // Array is valid if at most one "drop" exists
        return count <= 1;
    }
};