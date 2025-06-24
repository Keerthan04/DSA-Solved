class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if (!root) return {}; // Always check for null root

        queue<TreeNode*> q;
        q.push(root);
        vector<vector<int>> answer;
        int flag = 0; // 0 means L->R, 1 means R->L

        while (!q.empty()) {
            int size = q.size();
            vector<int> level;
            for (int i = 0; i < size; i++) {
                TreeNode* ele = q.front();
                q.pop();
                if (ele->left) q.push(ele->left);
                if (ele->right) q.push(ele->right);
                level.push_back(ele->val);
            }

            if (flag == 0) {
                answer.push_back(level);
                flag = 1;
            } else {
                reverse(level.begin(), level.end());//do first this then push cant direct as this returns a void
                answer.push_back(level);
                flag = 0;
            }
        }

        return answer;
    }
};
