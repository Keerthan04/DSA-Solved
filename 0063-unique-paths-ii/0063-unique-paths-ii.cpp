int solve(int m,int n,vector<vector<int>> &dp,vector<vector<int>> &v){
    //base conditions->when counting always see 1 for satisfieng cond and 0 for the other one
    if(m==0 &&n==0) return 1;//reached the destination so
    if(m<0 || n<0) return 0;//reached out of bounds
    if(v[m][n]==1) return 0;//as reached a place where obstacle so cant go there
    //dp check
    if(dp[m][n]!= -1) return dp[m][n];
    //now doing all possible stuff
    int up = solve(m-1,n,dp,v);//up so row up
    int left = solve(m,n-1,dp,v);
    return dp[m][n] = up+left;
}
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int>>dp(m,vector<int>(n,-1));
        if(obstacleGrid[0][0]==1) return 0;
        return solve(m-1,n-1,dp,obstacleGrid);
    }
};