class Solution {

bool isMirror(TreeNode* root1, TreeNode* root2){
    if(root1==NULL and root2==NULL)return true;
    if(root1==NULL or root2==NULL)return false;
return root1->val==root2->val
and isMirror(root1->left,root2->right)
and isMirror(root1->right,root2->left);
}
public:
    bool isSymmetric(TreeNode* root) {
        return isMirror(root->left,root->right);
    }
};