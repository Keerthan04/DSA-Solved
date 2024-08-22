int solve(int n, vector<int> &dp){
    if(n == 0){
        // Base condition: one way to stay at the ground
        return 1;
    }
    if(dp[n] != -1) return dp[n];

    int ways = 0;
    if(n >= 1) ways += solve(n-1, dp); // 1 step
    if(n >= 2) ways += solve(n-2, dp); // 2 steps
    
    return dp[n] = ways;
}

class Solution {
public:
    int climbStairs(int n) {
        vector<int> dp(n+1, -1);
        return solve(n, dp);
    }
};
