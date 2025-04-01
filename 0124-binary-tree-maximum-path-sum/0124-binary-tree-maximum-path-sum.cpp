#include <climits>  // Required for INT_MIN

class Solution {
public:
    int maxpathsum(TreeNode* root, int *maxi) {
        if (root == nullptr) {
            return 0;
        }
        
        // Calculate left and right subtree sum, ignore negative sums, if negative then take 0
        int leftsum = max(0, maxpathsum(root->left, maxi));
        int rightsum = max(0, maxpathsum(root->right, maxi));

        // Update maximum path sum considering current node as the root
        *maxi = max(*maxi, leftsum + rightsum + root->val);

        // Return the max path sum for one side (either left or right)
        return root->val + max(leftsum, rightsum);
    }

    int maxPathSum(TreeNode* root) {
        int maxi = INT_MIN;  // Initialize to handle negative values
        maxpathsum(root, &maxi);
        return maxi;
    }
};
