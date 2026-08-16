class  Solution {
public:
    int rangeSumBST(TreeNode* root, int low, int high) {
       if(root == NULL) return 0;
       int leftans= rangeSumBST(root->left,low,high);
       int rightans= rangeSumBST(root->right,low,high);
   int ans = leftans+rightans;
   if(root->val >= low and root->val <= high){
    ans += root->val;
   }
   return ans;
    }
};