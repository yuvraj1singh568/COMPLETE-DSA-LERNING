class Solution {

    int Max(TreeNode* root){
        while(root->right != NULL){
            root= root->right;
        }
        return root->val;
    }
    // int Min(TreeNode* root){
    //     while(root->left != NULL){
    //         root = root->left;
    //     }
    //     return root->val;
    // }

public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == NULL){
            return NULL;
        }
        // delete from left
        if(key<root->val){
            root->left = deleteNode(root->left,key);
        }
        // delete from right
        else if(key>root->val){
            root->right = deleteNode(root->right,key);
        } else{
         // key == root->val
         if(root->left == NULL and root->right == NULL){
            return NULL;
         }
         // only left child
         // leaf node
         if(root->left != NULL and root->right == NULL){
            return root->left;
         }
         //leaf right
         if(root->left == NULL and root->right != NULL){
            return root->right;
         }
         //both left and right child exist
         int mx= Max(root->left);
         root->val= mx;
         // delete mx form root->left recursively
         root->left = deleteNode(root->left,mx);
        }
        return root;
    }
};