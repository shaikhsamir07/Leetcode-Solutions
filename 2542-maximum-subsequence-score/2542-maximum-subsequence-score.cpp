class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {

        int n = nums1.size();

        vector<pair<int,int>> vp;

        // Store {nums2, nums1}
        for (int i = 0; i < n; i++) {
            vp.push_back({nums2[i], nums1[i]});
        }

        // Sort in descending order of nums2
        sort(vp.rbegin(), vp.rend());

        priority_queue<int, vector<int>, greater<int>> pq;

        long long sum = 0;
        long long ans = 0;

        for (auto &p : vp) {
            int minNums2 = p.first;
            int valNums1 = p.second;

            pq.push(valNums1);
            sum += valNums1;

            // Keep only k elements
            if (pq.size() > k) {
                sum -= pq.top();
                pq.pop();
            }

            // Calculate score when size == k
            if (pq.size() == k) {
                ans = max(ans, sum * 1LL * minNums2);
            }
        }

        return ans;
    }
};