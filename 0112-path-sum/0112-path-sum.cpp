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
    bool hasPathSum(TreeNode* root,
                    int targetSum) {

        // Empty tree
        if (root == nullptr) {
            return false;
        }

        // Leaf node
        if (root->left == nullptr &&
            root->right == nullptr) {

            return targetSum == root->val;
        }

        int remaining =
            targetSum - root->val;

        // Check left or right subtree
        return hasPathSum(root->left, remaining) ||
               hasPathSum(root->right, remaining);
    }
};