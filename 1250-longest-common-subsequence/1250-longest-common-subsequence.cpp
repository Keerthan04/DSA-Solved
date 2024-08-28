class Solution {
public:
    int solve(int i,int j,string &text1,string &text2,vector<vector<int>> &dp){
        //base condition
        if(i<0 || j<0) return 0;
        //dp check
        if(dp[i][j]!= -1) return dp[i][j];
        //do all possible things
        //if match
        if(text1[i]==text2[j]){
            return dp[i][j] =  1 + solve(i-1,j-1,text1,text2,dp);
        }
        //no match then(do the both possible thing)
        return dp[i][j] = max(solve(i-1,j,text1,text2,dp),solve(i,j-1,text1,text2,dp));
    }
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.length();int m = text2.length();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        return solve(n-1,m-1,text1,text2,dp);
    }
};