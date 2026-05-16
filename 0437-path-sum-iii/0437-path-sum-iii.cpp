class Solution {
public:
    int ans = 0;

    void dfs(TreeNode* node, long long currSum, int targetSum,
             unordered_map<long long, int>& prefixSum) {
        
        if (!node) return;

        currSum += node->val;

        // Check if there exists a prefix sum
        // such that currSum - prefix = target
        if (prefixSum.find(currSum - targetSum) != prefixSum.end()) {
            ans += prefixSum[currSum - targetSum];
        }

        // Add current prefix sum
        prefixSum[currSum]++;

        // Traverse left and right
        dfs(node->left, currSum, targetSum, prefixSum);
        dfs(node->right, currSum, targetSum, prefixSum);

        // Backtrack
        prefixSum[currSum]--;
    }

    int pathSum(TreeNode* root, int targetSum) {
        unordered_map<long long, int> prefixSum;

        // Base case: one way to have sum = 0
        prefixSum[0] = 1;

        dfs(root, 0, targetSum, prefixSum);

        return ans;
    }
};