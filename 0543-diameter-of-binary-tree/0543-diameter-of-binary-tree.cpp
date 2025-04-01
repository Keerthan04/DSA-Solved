class Solution {
public:
    int diaTree(TreeNode* root, int *maxi){
        if(root == NULL){
            return 0;
        }
        int lh = diaTree(root->left, maxi);
        int rh = diaTree(root->right, maxi);
        *maxi = max(*maxi, lh + rh);
        return 1 + max(lh, rh);
    }

    int diameterOfBinaryTree(TreeNode* root) {
        int maxi = 0;
        diaTree(root, &maxi);
        return maxi;
    }
};
