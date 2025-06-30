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
    TreeNode* markParentsAndReturnNode(TreeNode *root, unordered_map<TreeNode *, TreeNode *> &parents, int start)
    {
        queue<TreeNode *> q;
        q.push(root);
        TreeNode* mainNode=NULL;
        if(root->val == start) mainNode=root;
        while (!q.empty())
        {
            TreeNode *current = q.front();
            if(current->val == start)mainNode=current;
            q.pop();
            if (current->left)
            {
                parents[current->left] = current;
                q.push(current->left);
            }
            if (current->right)
            {
                parents[current->right] = current;
                q.push(current->right);
            }
        }
        return mainNode;
    }
    int amountOfTime(TreeNode* root, int start) {
        unordered_map<TreeNode *, TreeNode *> parents;
        TreeNode* target = markParentsAndReturnNode(root, parents,start);
        if(target == NULL) return 0;
        unordered_map<TreeNode *, bool> visited; // to mark visited nodes
        queue<TreeNode *> q;
        int curr_distance = 0;
        q.push(target); // start bfs with target
        visited[target] = true;
        while (!q.empty())
        {
            curr_distance++;
            int size = q.size();
            for (int i = 0; i < size; i++)
            {
                TreeNode *current = q.front();
                q.pop();
                if (current->left && !visited[current->left])
                {
                    q.push(current->left);
                    visited[current->left] = true;
                }
                if (current->right && !visited[current->right])
                {
                    q.push(current->right);
                    visited[current->right] = true;
                }
                if (parents[current] && !visited[parents[current]])
                {
                    q.push(parents[current]);
                    visited[parents[current]] = true;
                }
            }
        }
        return curr_distance-1;
    }
};