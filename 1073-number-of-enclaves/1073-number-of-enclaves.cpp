class Solution {
private:
    void bfs(int sr, int sc, vector<vector<int>>& vis, vector<vector<int>>& board, int n, int m) {
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
                    vis[nrow][ncol] == 0 && board[nrow][ncol] == 1) {
                    vis[nrow][ncol] = 1;
                    q.push({nrow, ncol});
                }
            }
        }
    }
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        for(int i =0;i<n;i++){
            if(!vis[i][0] && grid[i][0] == 1) bfs(i,0,vis,grid,n,m);
            if(!vis[i][m-1] && grid[i][m-1] == 1) bfs(i,m-1,vis,grid,n,m);
        }
        for (int j = 0; j < m; j++) {
            if (!vis[0][j] && grid[0][j] == 1) bfs(0, j, vis, grid, n, m);
            if (!vis[n - 1][j] && grid[n - 1][j] == 1) bfs(n - 1, j, vis, grid, n, m);
        }

        int cnt=0;
        for(int i =0;i<n;i++){
            for(int j =0;j<m;j++){
                if(!vis[i][j] && grid[i][j]==1){
                    cnt++;
                }
            }
        }
        return cnt;
    }
};