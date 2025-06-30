/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void markParents(TreeNode* root,unordered_map<TreeNode*,TreeNode*> &parents){
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* current = q.front();
            q.pop();
            if(current->left){
                parents[current->left] = current;
                q.push(current->left);
            }
            if(current->right){
                parents[current->right] = current;
                q.push(current->right);
            }
        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*,TreeNode*> parents;
        markParents(root,parents);
        unordered_map<TreeNode*,bool>visited;//to mark visited nodes
        queue<TreeNode*> q;
        int curr_distance = 0;
        q.push(target);//start bfs with target
        visited[target]=true;
        while(!q.empty()){
            if(curr_distance++ == k) break;//here only distance anyway will be increment so no need for us to do again
            int size = q.size();
            for(int i =0;i<size;i++){
                TreeNode* current = q.front();
                q.pop();
                if(current->left && !visited[current->left]){
                    q.push(current->left);
                    visited[current->left] = true;
                }
                if(current->right && !visited[current->right]){
                    q.push(current->right);
                    visited[current->right] = true;
                }
                if(parents[current] && !visited[parents[current]]){
                    q.push(parents[current]);
                    visited[parents[current]] = true;
                }
            }
        }
        //when we get result i.e after kth distance here we will be so
        vector<int> result;
        while(!q.empty()){
            // TreeNode* current = q.front();
            result.push_back(q.front()->val);q.pop();
        }
        return result;
    }
};