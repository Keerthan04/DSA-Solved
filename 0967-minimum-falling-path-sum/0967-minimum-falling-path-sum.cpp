class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        
        // DP table to store the minimum sum at each position
        vector<vector<int>> dp(m, vector<int>(n, 0));
        
        // Initialize the last row with the matrix values
        for (int j = 0; j < n; ++j) {
            dp[m - 1][j] = matrix[m - 1][j];
        }
        
        // Fill the DP table from the second-last row to the first row
        for (int i = m - 2; i >= 0; --i) {
            for (int j = 0; j < n; ++j) {
                int down = dp[i + 1][j];
                int leftDiagonal = (j > 0) ? dp[i + 1][j - 1] : INT_MAX;
                int rightDiagonal = (j < n - 1) ? dp[i + 1][j + 1] : INT_MAX;
                
                dp[i][j] = matrix[i][j] + min(down, min(leftDiagonal, rightDiagonal));
            }
        }
        
        // The result is the minimum value in the first row
        int mini = INT_MAX;
        for (int j = 0; j < n; ++j) {
            mini = min(mini, dp[0][j]);
        }
        
        return mini;
    }
};
