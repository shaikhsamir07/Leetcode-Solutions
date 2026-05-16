class Solution {
public:
    int ans = 0;

    void dfs(TreeNode* node, int leftLen, int rightLen) {
        if (!node) return;

        ans = max(ans, max(leftLen, rightLen));

        // Move left:
        // previous move should be right, so increase rightLen
        dfs(node->left, rightLen + 1, 0);

        // Move right:
        // previous move should be left, so increase leftLen
        dfs(node->right, 0, leftLen + 1);
    }

    int longestZigZag(TreeNode* root) {
        dfs(root, 0, 0);
        return ans;
    }
};