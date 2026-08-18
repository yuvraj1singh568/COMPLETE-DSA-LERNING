class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL) return NULL;
        if(root == p or root == q) return root;
        auto  leftAns =  lowestCommonAncestor(root->left,p,q);
        auto  rightAns =  lowestCommonAncestor(root->right,p,q);
        // LCA
        if(leftAns != NULL and rightAns != NULL){
            return root;
        }
        // one of the nodes exists in the left side
            if(leftAns != NULL and rightAns == NULL){
                return leftAns;
        }
        // one of the nodes exists in the right side
        if(leftAns == NULL and rightAns != NULL){
            return rightAns;
        }

          return NULL;
    }
};