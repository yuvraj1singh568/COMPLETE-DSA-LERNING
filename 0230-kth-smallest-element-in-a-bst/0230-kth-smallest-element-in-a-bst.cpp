class Solution {
    int ans  = 0;
    int cnt = 0;
 void helper(TreeNode *root, int k){
   if(root == NULL) return;
   helper(root->left,k);
   cnt++;
   if(cnt == k) ans = root->val;
   helper(root->right,k);
 }
public:
    int kthSmallest(TreeNode* root, int k) {
        helper(root ,k);
        return ans;    
    }
};