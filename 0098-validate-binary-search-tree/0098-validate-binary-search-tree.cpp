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
    void inorder(TreeNode* root, vector<int> &inorderList){
        if(root==NULL) return;
        inorder(root->left,inorderList);
        inorderList.push_back(root->val);
        inorder(root->right,inorderList);
    }
    bool isValidBST(TreeNode* root) {
        vector<int> inorderList;
        inorder(root,inorderList);
        int flag = 0;
        for(int i =1;i<inorderList.size();i++){
            if(inorderList[i] <= inorderList[i-1]){
                flag = 1;
                break;
            }
        }
        if(flag ==1)return false;
        return true;
    }
};