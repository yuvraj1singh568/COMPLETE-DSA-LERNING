class Solution {
void helper(TreeNode* root , vector<int>&ans){
    if(root == NULL) return;
    helper(root->left,ans);
    ans.push_back(root->val);
    helper(root->right,ans);
}




public:
    bool isValidBST(TreeNode* root) {
          vector<int> inorder;
          helper(root,inorder);
          for(int i=1;i<inorder.size();i++)
          {
            if(inorder[i] <= inorder[i-1]){
                return false;
            }
          }   
          return true;
    }
};