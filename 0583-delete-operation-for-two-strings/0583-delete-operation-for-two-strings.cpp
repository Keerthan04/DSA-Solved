class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.length();int m = text2.length();
        //shifting indexes here so we have extra n and m 
        vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
        for(int i=0;i<=m;i++) dp[0][i]=0;
        for(int j=0;j<=n;j++) dp[j][0]=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(text1[i-1]==text2[j-1]){
                    dp[i][j] = 1+dp[i-1][j-1];
                }
                else{
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        return dp[n][m];
    }
    int minDistance(string word1, string word2) {
        int lcs = longestCommonSubsequence(word1,word2);
        return (word1.length()-lcs) + (word2.length()-lcs);
    }
};