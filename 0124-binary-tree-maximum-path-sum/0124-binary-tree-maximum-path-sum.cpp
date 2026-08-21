class Solution {
    int ans = INT_MIN;

    int helper(TreeNode* root) {
        if (root == NULL)
            return 0;

        int left = max(0, helper(root->left));
        int right = max(0, helper(root->right));

        // Path passing through current node
        ans = max(ans, left + root->val + right);

        // Contribution to parent
        return root->val + max(left, right);
    }

public:
    int maxPathSum(TreeNode* root) {
        helper(root);
        return ans;
    }
};