class Solution {
public:

    int mini = INT_MAX;
    TreeNode* prev = NULL;

    void inorder(TreeNode* root) {

        if (!root)
            return;

        inorder(root->left);

        if (prev) {
            mini = min(mini, root->val - prev->val);
        }

        prev = root;

        inorder(root->right);
    }

    int getMinimumDifference(TreeNode* root) {

        inorder(root);

        return mini;
    }
};