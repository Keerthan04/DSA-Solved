class Solution {
private:
    void bfs(int sr, int sc, vector<vector<int>>& vis, vector<vector<char>>& board, int n, int m) {
        vis[sr][sc] = 1;
        queue<pair<int, int>> q;
        q.push({sr, sc});
        
        int delrow[4] = {-1, 0, 1, 0};
        int delcol[4] = {0, 1, 0, -1};
        
        while (!q.empty()) {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            
            for (int i = 0; i < 4; i++) {
                int nrow = row + delrow[i];
                int ncol = col + delcol[i];
                
                if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m &&
                    vis[nrow][ncol] == 0 && board[nrow][ncol] == 'O') {
                    vis[nrow][ncol] = 1;
                    q.push({nrow, ncol});
                }
            }
        }
    }

public:
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        
        // Step 1: Mark all 'O' connected to the boundary as visited
        for (int i = 0; i < n; i++) {
            if (!vis[i][0] && board[i][0] == 'O') bfs(i, 0, vis, board, n, m);
            if (!vis[i][m - 1] && board[i][m - 1] == 'O') bfs(i, m - 1, vis, board, n, m);
        }
        for (int j = 0; j < m; j++) {
            if (!vis[0][j] && board[0][j] == 'O') bfs(0, j, vis, board, n, m);
            if (!vis[n - 1][j] && board[n - 1][j] == 'O') bfs(n - 1, j, vis, board, n, m);
        }
        
        // Step 2: Flip all unvisited 'O' to 'X' and restore visited ones back to 'O'
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!vis[i][j] && board[i][j] == 'O') {
                    board[i][j] = 'X';
                }
            }
        }
    }
};
