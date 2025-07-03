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
    TreeNode* build(vector<int>&A,int &i,int bound){
        if(i==A.size() || A[i]>bound){
            //if reach end of preorder or val > bound(no node form)
            return NULL;
        }
        //else make node
        TreeNode* node = new TreeNode(A[i]);
        i++;
        //for left of node do call build with bound as node->val
        node->left = build(A,i,node->val);
        //for right of node do call build with same bound
        node->right = build(A,i,bound);
        return node;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int i =0;
        return build(preorder,i,INT_MAX);
    }
};