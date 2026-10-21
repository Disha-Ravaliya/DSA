
class Solution {
public:
    void dfs(TreeNode* root, int tS, vector<int>& path,
             vector<vector<int>>& ans) {

        if (root == nullptr) {
            return;
        }

        path.push_back(root->val);

        // Check whether we reached a leaf node
        if (root->left == nullptr && root->right == nullptr) {
            if (tS == root->val) {
                ans.push_back(path);
            }
        }

        // Explore left and right subtrees
        dfs(root->left, tS - root->val, path, ans);
        dfs(root->right, tS - root->val, path, ans);

        // Backtracking: remove the current node
        path.pop_back();
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        vector<int> path;

        dfs(root, targetSum, path, ans);

        return ans;
    }
};
