class Solution {
private:
    void bfs(int sr, int sc, int color, vector<vector<int>> &image, vector<vector<int>> &vis, int n, int m, int originalColor) {
        vis[sr][sc] = 1;
        queue<pair<int,int>> q;
        image[sr][sc] = color;
        q.push({sr, sc});
        
        int delrow[4] = {-1, 0, 1, 0};
        int delcol[4] = {0, 1, 0, -1};
        
        while (!q.empty()) {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            
            for (int k = 0; k < 4; k++) {
                int newrow = row + delrow[k];
                int newcol = col + delcol[k];
                
                // Check bounds, visit status, and color match
                if (newrow >= 0 && newrow < n && newcol >= 0 && newcol < m 
                    && !vis[newrow][newcol] && image[newrow][newcol] == originalColor) {
                    image[newrow][newcol] = color;
                    vis[newrow][newcol] = 1;
                    q.push({newrow, newcol});
                }
            }
        }
    }
    
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size();
        int m = image[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        
        int originalColor = image[sr][sc];
        if (originalColor != color) { // Avoid infinite loop when the target color is the same
            bfs(sr, sc, color, image, vis, n, m, originalColor);
        }
        
        return image;
    }
};
