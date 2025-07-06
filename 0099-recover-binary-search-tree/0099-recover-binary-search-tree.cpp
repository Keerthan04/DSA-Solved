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
private:
    TreeNode* first;
    TreeNode* middle;
    TreeNode* last;
    TreeNode* prev;

    void inorder(TreeNode* root){
        if(root == NULL) return;
        inorder(root->left);

        //now main logic
        if(prev!=NULL && (prev->val > root->val)){
            if(first==NULL){
                //means first violation
                first = prev;
                middle = root;
            }else{
                last = root;//second violation
            }
        }
        prev = root;//mark current as root
        inorder(root->right);
    }
public:
    void recoverTree(TreeNode* root) {
        first = middle = last = NULL;
        prev = new TreeNode(INT_MIN);
        inorder(root);
        if(first && last){
            //means non adjacent
            swap(first->val,last->val);
        }else if(first && middle) swap(first->val,middle->val);
    }
};