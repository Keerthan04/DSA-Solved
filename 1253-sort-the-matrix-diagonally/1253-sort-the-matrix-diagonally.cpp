class Solution {
public:
    void sortDiagonal(vector<vector<int>>& grid, int i, int j) {
        int n = grid.size(), m = grid[0].size();
        vector<int> diag;

        // collect diagonal elements
        int x = i, y = j;
        while(x < n && y < m) {
            diag.push_back(grid[x][y]);
            x++; y++;
        }

        sort(diag.begin(), diag.end());//sorted ascending only

        // put back sorted values
        x = i; y = j;
        int idx = 0;
        while(x < n && y < m) {
            grid[x][y] = diag[idx++];
            x++; y++;
        }
    }
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        if(mat.empty() || mat[0].empty()) return mat;
        int n = mat.size(), m = mat[0].size();  
        //each sorted ascending only
        for (int i = 0; i < n; ++i) sortDiagonal(mat, i, 0);

        for (int j = 1; j < m; ++j) sortDiagonal(mat, 0, j);

        return mat;
    }
};