class Solution {
public:

    int maxSubarraySumCircular(vector<int>& nums) {

        int totalSum = 0;

        int currMax = 0, maxSum = INT_MIN;
        int currMin = 0, minSum = INT_MAX;

        for (int num : nums) {

            // Kadane for maximum subarray
            currMax = max(num, currMax + num);
            maxSum = max(maxSum, currMax);

            // Kadane for minimum subarray
            currMin = min(num, currMin + num);
            minSum = min(minSum, currMin);

            totalSum += num;
        }

        // If all numbers are negative
        if (maxSum < 0)
            return maxSum;

        // Maximum of normal or circular subarray
        return max(maxSum, totalSum - minSum);
    }
};