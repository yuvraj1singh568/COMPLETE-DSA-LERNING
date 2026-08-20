class Solution {
 int findheight(TreeNode* root){
    if(root == NULL) return 0;
    int lh= findheight(root->left);
    int rh= findheight(root->right);
    return  1+ max(lh,rh);
  
 }
public:
    bool isBalanced(TreeNode* root) {
       if(root == NULL) return true;
      int lh = findheight(root->left);      
      int rh = findheight(root->right);
      if(abs(lh-rh)>1){
        return false;
      }      
      return isBalanced(root->left) and isBalanced(root->right);
    }
};