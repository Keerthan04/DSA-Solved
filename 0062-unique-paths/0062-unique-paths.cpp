int solve(int m,int n,vector<vector<int>> &dp){
    //base conditions->when counting always see 1 for satisfieng cond and 0 for the other one
    if(m==0 &&n==0) return 1;//reached the destination so
    if(m<0 || n<0) return 0;//reached out of bounds
    //dp check
    if(dp[m][n]!= -1) return dp[m][n];
    //now doing all possible stuff
    int up = solve(m-1,n,dp);//up so row up
    int left = solve(m,n-1,dp);
    return dp[m][n] = up+left;
}
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m,vector<int>(n,-1));
        return solve(m-1,n-1,dp);
    }
};