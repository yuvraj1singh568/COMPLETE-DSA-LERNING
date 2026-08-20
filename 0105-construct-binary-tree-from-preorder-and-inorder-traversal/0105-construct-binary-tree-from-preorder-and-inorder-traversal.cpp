class Solution {
   TreeNode* helper(vector<int>& preorder,vector<int>&inorder,int preStart,int preEnd,int inStart,int inEnd){
    if(preStart> preEnd) return NULL;
    
     auto root = new TreeNode(preorder[preStart]);
     int idx = -1;
     for(int i = inStart;i<= inEnd;i++){
        if(inorder[i]== root->val){
            idx = i;
            break;
        }
     }
     int letSubtreeSize = idx- inStart;
root->left= helper(preorder,inorder,preStart+1,preStart+letSubtreeSize,inStart,idx-1);
root->right= helper(preorder,inorder,preStart + letSubtreeSize+1,preEnd,idx+1,inEnd);
return root;
}
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder){
    int n = preorder.size();
    return helper(preorder,inorder,0,n-1,0,n-1);
    }


};