/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int maxDepth(TreeNode* root) {
        // 1. BASE CASE: If the tree is empty, depth is 0
        if (root == nullptr) {
            return 0;
        }

        // 2. THE DIVE: Ask the children for their heights
        int leftHeight = maxDepth(root->left);
        int rightHeight = maxDepth(root->right);

        // 3. THE TAKE BACK: Pick the winner, add 1 for 'this' level, and return
        return max(leftHeight, rightHeight) + 1;
    }
};