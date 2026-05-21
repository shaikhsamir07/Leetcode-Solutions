/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr),
 *                  right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr),
 *                       right(nullptr) {}
 *     TreeNode(int x, TreeNode *left,
 *              TreeNode *right)
 *         : val(x), left(left),
 *           right(right) {}
 * };
 */

class Solution {
public:

    int dfs(TreeNode* root, int current) {

        if (root == nullptr) {
            return 0;
        }

        // Build current number
        current = current * 10 + root->val;

        // Leaf node
        if (root->left == nullptr &&
            root->right == nullptr) {

            return current;
        }

        // Sum from left and right
        return dfs(root->left, current) +
               dfs(root->right, current);
    }

    int sumNumbers(TreeNode* root) {

        return dfs(root, 0);
    }
};