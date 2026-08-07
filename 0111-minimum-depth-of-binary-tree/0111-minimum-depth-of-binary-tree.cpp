class Solution {
public:
    /**
     * @brief Recursive Depth-First Search helper to find the minimum depth of a
     * binary tree.
     * @param root Current node being visited.
     * @param cnt Reference to the minimum depth tracker.
     * @param traceCount Current depth count from the root to the current node.
     */
    void dfs(TreeNode* root, int& cnt, int traceCount) {
        if (root == nullptr) {
            return;
        }

        // If it's a leaf node, check and update the minimum depth
        if (root->left == nullptr && root->right == nullptr) {
            cnt = min(cnt, traceCount);
            return;
        }

        // Traverse left (pass traceCount + 1 by value so it doesn't mess up the
        // right branch)
        if (root->left != nullptr) {
            dfs(root->left, cnt, traceCount + 1);
        }

        // Traverse right
        if (root->right != nullptr) {
            dfs(root->right, cnt, traceCount + 1);
        }
    }

    
    int minDepth(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }

        int cnt = INT_MAX;
        // Start traversal with root depth as 1
        dfs(root, cnt, 1);

        return cnt;
    }
};