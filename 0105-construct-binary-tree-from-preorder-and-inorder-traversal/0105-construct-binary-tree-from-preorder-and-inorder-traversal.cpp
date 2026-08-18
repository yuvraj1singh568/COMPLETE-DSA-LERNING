class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
       if(preorder.size() == 0){
        return NULL;
       }
       auto root = new TreeNode(preorder[0]);
       int idx = -1;
       for(int i=0;i<inorder.size();i++){
        if(inorder[i] == root->val){
            idx = i;
            break;
        }
        } 
  vector<int> preorderleft;
  vector<int> preorderright;
for(int i=1;i<=idx;i++){
    preorderleft.push_back(preorder[i]);
}
for(int i=idx+1;i<preorder.size();i++){
    preorderright.push_back(preorder[i]);
}
vector<int>inorderleft;
vector<int>inorderright;
for(int i=0;i<idx;i++){
    inorderleft.push_back(inorder[i]);
}
for(int i=idx+1;i<inorder.size();i++){
    inorderright.push_back(inorder[i]);
}
root->left= buildTree(preorderleft,inorderleft);
root->right= buildTree(preorderright,inorderright);
return root;
    }
};