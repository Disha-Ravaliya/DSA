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

    // here 2 pointer so sorted array needed so i can use inorder not pre , so use pre and also sort them
public:
    void preorder(TreeNode* root , vector<int> &v){
        if(root == nullptr) {return;}
        v.push_back(root->val);
          preorder(root->left,v);
          preorder(root->right,v);

    }
    bool findTarget(TreeNode* root, int k) {
        if(root == nullptr) return false;
        vector<int>v;
        preorder(root , v);

        int len = v.size();
        sort(v.begin(),v.end());

        int left = 0 ;
        int right = len -1;

        while(left<right){
            int sum = v[left] + v[right];

            if(sum == k) {
                return true;
            }else if(sum <k ){
                left++;

            }else {
                right--;
            }
        }


        return false;
    }
};