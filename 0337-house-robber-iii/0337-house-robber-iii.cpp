class Solution {
public:
    pair<int, int> solve(TreeNode* root) {
        if (!root)
            return {0, 0};

        auto left = solve(root->left);
        auto right = solve(root->right);

        int robThis = root->val + left.second + right.second;

        int notRobThis = max(left.first, left.second) +
                         max(right.first, right.second);

        return {robThis, notRobThis};
    }

    int rob(TreeNode* root) {
        auto ans = solve(root);

        return max(ans.first, ans.second);
    }
};