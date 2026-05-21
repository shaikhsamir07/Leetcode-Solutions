class Solution {
public:
    int removeDuplicates(vector<int>& nums) {

        int k = 0;

        for (int num : nums) {

            // Keep element if:
            // less than 2 elements OR
            // current num is greater than nums[k-2]
            if (k < 2 || num > nums[k - 2]) {

                nums[k] = num;
                k++;
            }
        }

        return k;
    }
};