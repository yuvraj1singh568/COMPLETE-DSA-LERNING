class Solution {
    void preOrder(TreeNode* root, vector<TreeNode*>& nodes) {
        if (root == NULL) return;

        nodes.push_back(root);

        preOrder(root->left, nodes);
        preOrder(root->right, nodes);
    }

public:
    void flatten(TreeNode* root) {
        vector<TreeNode*> nodes;

        preOrder(root, nodes);

        for (int i = 0; i + 1 < nodes.size(); i++) {
            nodes[i]->left = NULL;
            nodes[i]->right = nodes[i + 1];
        }
    }
};
