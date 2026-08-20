class Solution {
    unordered_map<int, int> idxs;

    TreeNode* helper(vector<int>& preorder, vector<int>& inorder,
                     int preStart, int preEnd,
                     int inStart, int inEnd) {

        if (preStart > preEnd)
            return NULL;

        TreeNode* root = new TreeNode(preorder[preStart]);

        int idx = idxs[root->val];

        int leftSubtreeSize = idx - inStart;

        root->left = helper(
            preorder, inorder,
            preStart + 1,
            preStart + leftSubtreeSize,
            inStart,
            idx - 1
        );

        root->right = helper(
            preorder, inorder,
            preStart + leftSubtreeSize + 1,
            preEnd,
            idx + 1,
            inEnd
        );

        return root;
    }

public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {

        int n = preorder.size();

        // Need to know the index of each value in inorder
        for (int i = 0; i < n; i++) {
            idxs[inorder[i]] = i;
        }

        return helper(preorder, inorder, 0, n - 1, 0, n - 1);
    }
};