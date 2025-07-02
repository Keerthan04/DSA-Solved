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
    TreeNode* helper(TreeNode* root){
        //this is to return the new after deleting the root
        //the logic is to get right child find last right of left and attach to r of that and return the left child
        if(root->left == NULL){
            return root->right;//if no left child only then return right
        }else if(root->right == NULL){
            return root->left;
        }
        TreeNode* rightchild = root->right;
        TreeNode* lastrightofleftchild = findLastRight(root->left);
        lastrightofleftchild->right = rightchild;
        return root->left;
    }
    TreeNode* findLastRight(TreeNode* root){
        if(root->right == NULL){
            return root;
        }
        return findLastRight(root->right);
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root== NULL){
            return NULL;
        }
        if(root->val == key){
            return helper(root);
        }
        TreeNode* dummy = root;
        while(root!=NULL){
            if(root->val > key){
                //move left
                if(root->left!=NULL && root->left->val == key){
                    root->left = helper(root->left);
                    //so node ka left will get attached with new
                    break;
                }else{
                    //else just move left
                    root = root->left;
                }
            }else{
                if(root->right!=NULL && root->right->val == key){
                    root->right = helper(root->right);
                    //so node ka right will get attached with new
                    break;
                }else{
                    //else just move left
                    root = root->right;
                }
            }
        }
        return dummy;
    }
};