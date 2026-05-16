class Solution {
public:
    int findPeakElement(vector<int>& nums) {

        int left = 0;
        int right = nums.size() - 1;

        while (left < right) {

            int mid = left + (right - left) / 2;

            // Peak is on the right side
            if (nums[mid] < nums[mid + 1]) {
                left = mid + 1;
            }
            // Peak is on the left side or at mid
            else {
                right = mid;
            }
        }

        return left;
    }
};