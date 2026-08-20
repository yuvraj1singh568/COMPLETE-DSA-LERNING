class Solution {
 int findheight(TreeNode* root){
   if(root == NULL) return 0;
   int lh = findheight(root->left);
   int rh = findheight(root->right);
   return 1+max(lh,rh);
 }
public:
    int diameterOfBinaryTree(TreeNode* root) {
           if(root == NULL) return 0;
           int lh = findheight(root->left);        
           int rh = findheight(root->right); 
           int leftAns = diameterOfBinaryTree(root->left);       
           int rightAns = diameterOfBinaryTree(root->right);
           return max({leftAns,rightAns,lh+rh});       
    }
};