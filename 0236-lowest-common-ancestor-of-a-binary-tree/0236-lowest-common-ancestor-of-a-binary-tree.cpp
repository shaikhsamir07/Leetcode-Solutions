/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root,
                                   TreeNode* p,
                                   TreeNode* q) {

        // Base case
        if (root == NULL || root == p || root == q) {
            return root;
        }

        TreeNode* left =
            lowestCommonAncestor(root->left, p, q);

        TreeNode* right =
            lowestCommonAncestor(root->right, p, q);

        // Both nodes found in different subtrees
        if (left != NULL && right != NULL) {
            return root;
        }

        // Return non-null subtree
        return (left != NULL) ? left : right;
    }
};