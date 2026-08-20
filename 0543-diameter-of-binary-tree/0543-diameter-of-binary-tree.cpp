struct Data{
    int height = 0;
    int diameter = 0;
};
class Solution {
 Data Solve(TreeNode* root){
   if(root == NULL) return Data();
   auto leftAns = Solve(root->left);
   auto rightAns = Solve(root->right);
   Data ans;
   ans.height = 1 + max(leftAns.height,rightAns.height);
   ans.diameter = max({leftAns.diameter,rightAns.diameter,leftAns.height+rightAns.height});
   return ans;
 }
public:
    int diameterOfBinaryTree(TreeNode* root) {
         return Solve(root).diameter;
    }
};