class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        queue<pair<pair<int, int>, int>> q; // {{row, col}, time}
        int fresh = 0; // Count of fresh oranges
        
        // Initialize the queue and count fresh oranges
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 2) {
                    q.push({{i, j}, 0}); // Rotten orange
                } else if (grid[i][j] == 1) {
                    fresh++; // Fresh orange
                }
            }
        }
        
        int tm = 0;
        int delrow[4] = {-1, 0, 1, 0};
        int delcol[4] = {0, 1, 0, -1};
        
        // BFS to rot the fresh oranges
        while (!q.empty()) {
            int r = q.front().first.first;
            int c = q.front().first.second;
            int t = q.front().second;
            q.pop();
            tm = max(tm, t);
            
            for (int k = 0; k < 4; k++) {
                int nrow = r + delrow[k];
                int ncol = c + delcol[k];
                
                // Check for valid fresh orange
                if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && grid[nrow][ncol] == 1) {
                    grid[nrow][ncol] = 2; // Mark as rotten
                    fresh--; // Decrease fresh count
                    q.push({{nrow, ncol}, t + 1});
                }
            }
        }
        
        // If fresh oranges remain, return -1
        return fresh == 0 ? tm : -1;
    }
};
