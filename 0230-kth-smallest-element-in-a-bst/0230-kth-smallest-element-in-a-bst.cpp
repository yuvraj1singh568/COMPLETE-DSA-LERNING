class Solution {
 void helper(TreeNode *root,vector<int> &ans){
    if(root == NULL) return;
    helper(root->left,ans);
    ans.push_back(root->val);
      helper(root->right,ans);
 }
public:
    int kthSmallest(TreeNode* root, int k) {
         vector<int> inorder;
         helper(root,inorder);
         return inorder[k-1];     
    }
};