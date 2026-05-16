class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        // Min-heap
        priority_queue<int, vector<int>, greater<int>> pq;

        for (int num : nums) {
            pq.push(num);

            // Keep only k largest elements
            if (pq.size() > k) {
                pq.pop();
            }
        }

        // Top is kth largest
        return pq.top();
    }
};