class Solution {
public:
    int solve(int m,int n,vector<vector<int>>& grid, vector<vector<int>>& moveCost,vector<vector<int>>&dp){
        if(m == 0) return grid[m][n]; // base: first row value
        if(dp[m][n] != -1) return dp[m][n];
        
        int mini = INT_MAX;
        // explore all columns in previous row(trick is in move cost as it is from cell value where we are coming from i.e i so use grid and get prev row and col ka and then the j is the col we are in now so that is just n)
        for(int j = 0; j < grid[0].size(); j++){
            int ans = grid[m][n] 
                      + moveCost[grid[m-1][j]][n] 
                      + solve(m-1, j, grid, moveCost, dp);
            mini = min(mini, ans);
        }
        return dp[m][n] = mini;
    }

    int minPathCost(vector<vector<int>>& grid, vector<vector<int>>& moveCost) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        
        int mini = INT_MAX;
        for(int i = 0; i < n; i++){
            mini = min(mini, solve(m-1, i, grid, moveCost, dp));
        }
        return mini;
        //case where reach to last so we can run for all the last nodes then find the minimum answer to it
    }
};
