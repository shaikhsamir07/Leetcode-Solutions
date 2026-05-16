class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {

        int n = costs.size();

        priority_queue<int, vector<int>, greater<int>> leftHeap;
        priority_queue<int, vector<int>, greater<int>> rightHeap;

        int left = 0;
        int right = n - 1;

        // Fill left heap
        for (int i = 0; i < candidates && left <= right; i++) {
            leftHeap.push(costs[left++]);
        }

        // Fill right heap
        for (int i = 0; i < candidates && left <= right; i++) {
            rightHeap.push(costs[right--]);
        }

        long long total = 0;

        for (int hire = 0; hire < k; hire++) {

            int leftCost = leftHeap.empty() ? INT_MAX : leftHeap.top();
            int rightCost = rightHeap.empty() ? INT_MAX : rightHeap.top();

            // Choose smaller cost
            if (leftCost <= rightCost) {
                total += leftCost;
                leftHeap.pop();

                if (left <= right) {
                    leftHeap.push(costs[left++]);
                }
            }
            else {
                total += rightCost;
                rightHeap.pop();

                if (left <= right) {
                    rightHeap.push(costs[right--]);
                }
            }
        }

        return total;
    }
};