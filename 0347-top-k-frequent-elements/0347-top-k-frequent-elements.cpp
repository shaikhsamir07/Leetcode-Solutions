class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {

        unordered_map<int, int> freq;

        // Count frequencies
        for (int num : nums) {
            freq[num]++;
        }

        // Bucket sort
        vector<vector<int>> bucket(nums.size() + 1);

        for (auto& it : freq) {

            int num = it.first;
            int count = it.second;

            bucket[count].push_back(num);
        }

        vector<int> ans;

        // Traverse from highest frequency
        for (int i = nums.size(); i >= 0; i--) {

            for (int num : bucket[i]) {

                ans.push_back(num);

                if (ans.size() == k) {
                    return ans;
                }
            }
        }

        return ans;
    }
};