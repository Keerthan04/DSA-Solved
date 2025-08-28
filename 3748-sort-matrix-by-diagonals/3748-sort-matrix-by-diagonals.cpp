class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        if(grid.empty() || grid[0].empty()) return grid;
        int n = grid.size(), m = grid[0].size();

        // Sort diagonals starting from first column
        for(int i = 0; i < n; i++) {
            sortDiagonal(grid, i, 0, false);  // descending
        }

        // Sort diagonals starting from first row (excluding [0,0]) as only upper we need
        for(int j = 1; j < m; j++) {
            sortDiagonal(grid, 0, j, true); // ascending
        }

        return grid;
    }

    void sortDiagonal(vector<vector<int>>& grid, int i, int j, bool ascending) {
        int n = grid.size(), m = grid[0].size();
        vector<int> diag;

        // collect diagonal elements
        int x = i, y = j;
        while(x < n && y < m) {
            diag.push_back(grid[x][y]);
            x++; y++;
        }

        // sort based on direction
        if(ascending)
            sort(diag.begin(), diag.end());
        else
            sort(diag.rbegin(), diag.rend());

        // put back sorted values
        x = i; y = j;
        int idx = 0;
        while(x < n && y < m) {
            grid[x][y] = diag[idx++];
            x++; y++;
        }
    }
};
