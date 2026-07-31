
class Solution {
public:
    bool isSameTree(TreeNode* root1, TreeNode* root2) {
        if(root1 == NULL and root2 ==NULL) return true;
        if(root1 == NULL or root2 ==NULL) return false;
    return root1->val==root2->val and isSameTree(root1->left,root2->left) and
    isSameTree(root1->right,root2->right);
    }
};