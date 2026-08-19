class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {

        int n = preorder.size();

        if (n == 0) {
            return NULL;
        }

        TreeNode* root = new TreeNode(preorder[0]);

        int idx = -1;

        // Find root in INORDER
        for (int i = 0; i < n; i++) {
            if (inorder[i] == root->val) {
                idx = i;
                break;
            }
        }

        vector<int> preorderLeft, inorderLeft;
        vector<int> preorderRight, inorderRight;

        // Left subtree
        for (int i = 1; i <= idx; i++) {
            preorderLeft.push_back(preorder[i]);
        }

        for (int i = 0; i < idx; i++) {
            inorderLeft.push_back(inorder[i]);
        }

        // Right subtree
        for (int i = idx + 1; i < n; i++) {
            preorderRight.push_back(preorder[i]);
        }

        for (int i = idx + 1; i < n; i++) {
            inorderRight.push_back(inorder[i]);
        }

        root->left = buildTree(preorderLeft, inorderLeft);
        root->right = buildTree(preorderRight, inorderRight);

        return root;
    }
};