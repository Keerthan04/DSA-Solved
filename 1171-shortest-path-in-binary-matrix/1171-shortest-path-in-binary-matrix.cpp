class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        pair<int, int> source = {0, 0};
        pair<int, int> destination = {n - 1, m - 1};
        
        // Check for blocked source or destination
        if (grid[0][0] == 1 || grid[n - 1][m - 1] == 1) return -1;

        // If source is the destination
        if (source == destination) return 1;

        // Initialize BFS
        queue<pair<int, pair<int, int>>> q;
        vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
        dist[source.first][source.second] = 1;
        q.push({1, {source.first, source.second}});

        while (!q.empty()) {
            auto it = q.front();
            q.pop();
            int dis = it.first;
            int r = it.second.first;
            int c = it.second.second;

            // Explore all 8 possible directions
            for (int i = -1; i <= 1; i++) {
                for (int j = -1; j <= 1; j++) {
                    if (i == 0 && j == 0) continue; // Skip no movement
                    
                    int nr = r + i;
                    int nc = c + j;

                    // Check validity of the next cell
                    if (nr >= 0 && nr < n && nc >= 0 && nc < m && grid[nr][nc] == 0 && dis + 1 < dist[nr][nc]) {
                        dist[nr][nc] = dis + 1;
                        if (nr == destination.first && nc == destination.second) return dis + 1;
                        q.push({dis + 1, {nr, nc}});
                    }
                }
            }
        }

        return -1; // Path not found
    }
};
