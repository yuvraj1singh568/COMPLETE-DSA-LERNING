/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(p->val > q->val){
            swap(p,q);
        }
          if(root == p or root == q) {
            return root;
          }
          if(p->val < root->val and root->val < q->val){
            return root;
          }
          // increase
          if(root->val < p->val){
           return  lowestCommonAncestor(root->right, p , q);        
          }
          // decrease
         return lowestCommonAncestor(root->left,p,q);
          
    }
    
};