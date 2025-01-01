class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();
        
        // Priority queue: {effort, {row, col}}
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> pq;
        vector<vector<int>> dist(n, vector<int>(m, 1e9));
        
        dist[0][0] = 0;
        pq.push({0, {0, 0}});
        
        int delrow[] = {-1, 0, 1, 0};
        int delcol[] = {0, 1, 0, -1};
        
        while (!pq.empty()) {
            auto [effort, cell] = pq.top();
            pq.pop();
            
            int r = cell.first;
            int c = cell.second;
            
            if (r == n - 1 && c == m - 1) {
                return effort; // Reached destination
            }
            
            for (int i = 0; i < 4; i++) {
                int nr = r + delrow[i];
                int nc = c + delcol[i];
                
                if (nr >= 0 && nr < n && nc >= 0 && nc < m) {
                    int newEffort = max(effort, abs(heights[nr][nc] - heights[r][c]));
                    if (newEffort < dist[nr][nc]) {
                        dist[nr][nc] = newEffort;
                        pq.push({newEffort, {nr, nc}});
                    }
                }
            }
        }
        
        return -1;
    }
};