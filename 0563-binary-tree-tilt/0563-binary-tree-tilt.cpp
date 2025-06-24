/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int find(TreeNode*root, int*sum){
        if(root==NULL) return 0;
        int lsum = find(root->left , sum);
        int rsum = find(root->right, sum);
        *sum = *sum + abs(lsum-rsum);
        return root->val + lsum+rsum;
    }
    int findTilt(TreeNode* root) {
        int sum = 0;
        find(root,&sum);
        return sum;
    }
};