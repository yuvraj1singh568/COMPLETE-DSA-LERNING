class  Solution {
public:
    int rangeSumBST(TreeNode* root, int low, int high) {
       if(root == NULL) return 0;
       int ans=0;
       if(root->val >= low){
        ans += rangeSumBST(root->left,low,high);
       }
       if(root->val <= high){
        ans+= rangeSumBST(root->right,low,high);
       }
   if(root->val >= low and root->val <= high){
    ans += root->val;
   }
   return ans;
    }
};