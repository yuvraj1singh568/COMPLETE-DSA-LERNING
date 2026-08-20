struct Data{
    int height = 0;
    bool isBalanced = true;
};
class Solution {
     Data Solve(TreeNode* root){
      if(root == NULL) return Data();
      auto leftAns = Solve(root->left);
      auto rightAns = Solve(root->right);

      Data ans;
      ans.height = 1 + max(leftAns.height , rightAns.height);
      ans.isBalanced = leftAns.isBalanced and rightAns.isBalanced and abs(leftAns.height - rightAns.height) <= 1;
      return ans;
     }
public:
    bool isBalanced(TreeNode* root) {
    return Solve(root).isBalanced;    
    }
};