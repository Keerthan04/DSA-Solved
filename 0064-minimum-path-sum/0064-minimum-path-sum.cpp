int solve(int m, int n, vector<vector<int>>& dp, vector<vector<int>>& grid) {
    if(m == 0 && n == 0) return grid[m][n];  // Base case: start point
    if(dp[m][n] != -1) return dp[m][n];

    int upSum = INT_MAX, leftSum = INT_MAX;
    if(m > 0) upSum = grid[m][n] + solve(m-1, n, dp, grid);   // Move from above
    if(n > 0) leftSum = grid[m][n] + solve(m, n-1, dp, grid); // Move from left

    return dp[m][n] = min(upSum, leftSum);
}

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return solve(m-1, n-1, dp, grid);
    }
};
