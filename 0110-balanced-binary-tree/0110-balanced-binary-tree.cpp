class Solution {
public:
    int checkHeight(TreeNode* root) {
        if (root == nullptr) return 0;

        int left = checkHeight(root->left);
        if (left == -1) return -1;  // Left subtree is unbalanced

        int right = checkHeight(root->right);
        if (right == -1) return -1;  // Right subtree is unbalanced

        if (abs(left - right) > 1) return -1;  // Current tree is unbalanced

        return 1 + max(left, right);
    }

    bool isBalanced(TreeNode* root) {
        return checkHeight(root) != -1;
    }
};
